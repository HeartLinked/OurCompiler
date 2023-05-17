#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

extern int cnt;

int gen();

class SymbolTable {
  public:
    // 插入新符号，如果符号已经存在，返回 false，否则返回 true
    bool insertConstSymbol(const std::string &name, std::string value) {
        // 如果符号已经存在，返回 false
        if (table.find(name) != table.end() || table_variable.find(name) != table_variable.end()) {
            return false;
        }
        // 插入新符号
        table[name] = value;
        return true;
    }

    // 插入新符号，如果符号已经存在，返回 false，否则返回 true
    bool insertVirableSymbol(const std::string &name, std::string value) {
        // 如果符号已经存在，返回 false
        if (table_variable.find(name) != table_variable.end() || table.find(name) != table.end()) {
            return false;
        }
        // 插入新符号
        table_variable[name] = value;
        return true;
    }
    
    void changeValue(const std::string &name, std::string value) {
        if (table_variable.find(name) != table_variable.end()) {
            table_variable[name] = value;
        } else {
            table[name] = value;
        }
    }

    bool isConst(const std::string &name) const {
        auto iter = table.find(name);
        if (iter == table.end()) {
            return false;
        }
        return true;
    }

    bool isVirable(const std::string &name) const {
        auto iter = table_variable.find(name);
        if (iter == table_variable.end()) {
            return false;
        }
        return true;
    }

    int getConstValue(const std::string &name) const {
        auto iter = table.find(name);
        string s = iter->second;
        return stoi(s);
    }

    int getVirableValue(const std::string &name) const {
        auto iter = table_variable.find(name);
        string s = iter->second;
        return stoi(s);
    }

    void output() {
        cout << "const table:" << endl;
        for (auto iter = table.begin(); iter != table.end(); iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << "--------------------------" << endl;
        cout << "variable table:" << endl;
        for (auto iter = table_variable.begin(); iter != table_variable.end(); iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;
    }

  private:
    std::unordered_map<std::string, std::string> table;
    std::unordered_map<std::string, std::string> table_variable;
};

extern SymbolTable symbolTable;

// 遍历 AST 的返回值的数据结构
struct Data {

    // mode = 1 表示返回的value是常量的数值
    // mode = 2 表示返回的是变量本身，其中的变量名在 name 中，使用时需在前面加上@
    // mode = 3 表示返回的是含变量的表达式，其内容在 symbol 中，使用时需在前面加上%
    // mode = 0 表示返回的不是表达式类型
    Data(int mode, int value, string name, string symbol)
        : mode(mode), value(value), name(name), symbol(symbol) {}

    int mode;
    int value;
    string name;
    string symbol;

};

// 所有 AST 的基类
class BaseAST {
  public:
    virtual ~BaseAST() = default;

    virtual void Dump() const = 0;

    virtual Data Traverse() const = 0;
};

// CompUnit := FuncDef
class CompUnitAST : public BaseAST {
  public:
    // 程序目前只由一个函数组成
    std::unique_ptr<BaseAST> func_def;

    void Dump() const override {
        cerr << "Dump CompUnitAST" << endl;
        std::cout << "CompUnitAST { ";
        func_def->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        // Dump();  这里疑似暂时不用输出
        cerr << "Traverse CompUnitAST" << endl;
        func_def->Traverse();
        return Data(0, 0, "", "");
    }
};

// FuncDef := FuncType IDENT '(' ')' Block
class FuncDefAST : public BaseAST {
  public:
    // 函数返回值类型
    std::unique_ptr<BaseAST> func_type;
    // 函数名
    std::string func_name;
    // 函数内目前只有一个入口基本块
    std::unique_ptr<BaseAST> func_block;

    void Dump() const override {
        cerr << "Dump FuncDefAST" << endl;
        std::cout << "FuncDefAST { ";
        func_type->Dump();
        std::cout << ", " << func_name << ", ";
        // std::cout << "arglist: " << arglist << std::endl;
        func_block->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse FuncDefAST" << endl;
        cout << "fun @" << func_name << "(): ";
        func_type->Traverse();
        cout << "{" << endl;
        func_block->Traverse();
        cout << "}" << endl;
        return Data(0, 0, "", "");
    }
};

// Decl := ConstDecl
// Decl := VarDecl
class DeclAST : public BaseAST {
  public:
    int mode; // 1: const 2: var
    // 常量声明
    std::unique_ptr<BaseAST> const_decl;
    // 变量声明
    std::unique_ptr<BaseAST> var_decl;

    void Dump() const override {
        cerr << "Dump DeclAST" << endl;
        std::cout << "DeclAST { ";
        if(mode == 1) const_decl->Dump();
        else var_decl->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse DeclAST" << endl;
        if(mode == 1)
            const_decl->Traverse();
        else
            var_decl->Traverse();
        return Data(0, 0, "", "");
    }
};

// ConstDecl := "const" Btype ConstDef {"," ConstDef} ";"
class ConstDeclAST : public BaseAST {
  public:
    // 常量类型
    std::unique_ptr<BaseAST> b_type;
    // 常量定义
    std::unique_ptr<vector<unique_ptr<BaseAST>>> const_defs;

    void Dump() const override {
        cerr << "Dump ConstDecl" << endl;
        std::cout << "ConstDecl { ";
        b_type->Dump();
        std::cout << ", ";
        for (auto &const_def : *const_defs) {
            const_def->Dump();
            std::cout << ", ";
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse ConstDecl" << endl;
        for (auto &const_def : *const_defs) {
            const_def->Traverse();
        }
        return Data(0, 0, "", "");
    }
};

// BType := "int"
class BTypeAST : public BaseAST {
  public:
    // 类型
    std::string btype;

    void Dump() const override {
        cerr << "Dump BTypeAST" << endl;
        std::cout << "BTypeAST { ";
        std::cout << btype;
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse BtypeAST" << endl;
        /*    if (btype == "int") {
                cout << "i32 ";
            } else {
                // TODO
            }*/
        return Data(0, 0, "", "");
    }
};

// ConstDef := IDENT "=" ConstInitVal
class ConstDefAST : public BaseAST {
  public:
    // 常量名
    std::string const_name;
    // 常量初始值
    std::unique_ptr<BaseAST> const_init_val;

    void Dump() const override {
        cerr << "Dump ConstDef" << endl;
        std::cout << "ConstDef { ";
        std::cout << const_name << ", ";
        const_init_val->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse ConstDef" << endl;
        Data x = const_init_val->Traverse();
        // Insert const paramter const_name with symbol '%x'
        if(symbolTable.insertConstSymbol(const_name, to_string(x.value))){
            // cerr << "Insert const " << const_name << " as const number " << x.value << endl;
        } else {
            cerr << "Error: const " << const_name << " has been defined" << endl;
        }
        return x;
    }
};

// ConstInitVal := ConstExp
class ConstInitValAST : public BaseAST {
  public:
    // 常量表达式
    std::unique_ptr<BaseAST> const_exp;

    void Dump() const override {
        cerr << "Dump ConstInitValAST" << endl;
        std::cout << "ConstInitValAST { ";
        const_exp->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse ConstInitValAST" << endl;
        Data d = const_exp->Traverse();
        return d;
    }
};

// VarDecl := BType VarDef {"," VarDef} ";"
class VarDeclAST : public BaseAST {
  public:
    // 变量类型
    std::unique_ptr<BaseAST> b_type;
    // 变量定义
    std::unique_ptr<vector<unique_ptr<BaseAST>>> var_defs;

    void Dump() const override {
        cerr << "Dump VarDeclAST" << endl;
        std::cout << "VarDeclAST { ";
        b_type->Dump();
        std::cout << ", ";
        for (auto &var_def : *var_defs) {
            var_def->Dump();
            std::cout << ", ";
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse VarDeclAST" << endl;
        for (auto &var_def : *var_defs) {
            var_def->Traverse();
        }
        return Data(0, 0, "", "");
    }
};

// VarDef := IDENT
// VarDef := IDENT "=" InitVal
class VarDefAST : public BaseAST {
  public:
    int mode; // 1: IDENT 2: IDENT "=" InitVal
    // 变量名
    std::string var_name;
    // 变量初始值
    std::unique_ptr<BaseAST> init_val;

    void Dump() const override {
        cerr << "Dump VarDefAST" << endl;
        std::cout << "VarDefAST { ";
        std::cout << var_name << ", ";
        if (init_val != nullptr) {
            init_val->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse VarDefAST" << endl;
        if(mode == 1){  // int a;
            if(symbolTable.insertVirableSymbol(var_name, "0")){
                cerr << "Insert" << var_name << " as var: 0" << endl;
            } else {
                cerr << "Error: redefined variable " << var_name << endl;
            }
            cout << "   @" << var_name << " = alloc i32" << endl;
            cout << "   store 0, @" << var_name << endl;
            return Data(0, 0, "", "");
        }
        else {           // int a = x + 1; 
            Data d = init_val->Traverse();
            if(symbolTable.insertVirableSymbol(var_name, to_string(d.value))){
                cerr << "Insert" << var_name << " as variale"  <<endl;
            } else {
                cerr << "Error: redefined variable " << var_name << endl;
            }
            cout << "   @" << var_name << " = alloc i32" << endl;
            if(d.mode == 1){
                cout << "   store " << d.value << ", @" << var_name << endl;
            } else if(d.mode == 2){
                cout << "   store @" << d.name << ", @" << var_name << endl;
            } else if(d.mode == 3) {
                cout << "   store %" << d.symbol << ", @" << var_name << endl; 
            } else {
              throw runtime_error("Error: Init variable error");
            }
            return Data(0, 0, "", "");
        }
    }
};

// InitVal := Exp
class InitValAST : public BaseAST {
  public:
    // 表达式
    std::unique_ptr<BaseAST> exp;

    void Dump() const override {
        cerr << "Dump InitValAST" << endl;
        std::cout << "InitValAST { ";
        exp->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse InitValAST" << endl;
        Data d = exp->Traverse();
        return d;
    }
};

// ------------------------------

// FuncType := Type
class FuncTypeAST : public BaseAST {
  public:
    // 函数返回值类型
    std::string type;

    void Dump() const override {
        cerr << "Dump FuncTypeAST" << endl;
        std::cout << "FuncTypeAST { ";
        std::cout << type;
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse FuncTypeAST" << endl;
        if (type == "int") {
            cout << "i32 ";
        } else {
            // TODO
        }
        return Data(0, 0, "", "");
    }
};

// Block := '{' {BlockItem} '}'
class BlockAST : public BaseAST {
  public:
    std::unique_ptr<vector<unique_ptr<BaseAST>>> block_items;

    void Dump() const override {
        cerr << "Dump BlockAST" << endl;
        std::cout << "BlockAST { ";
        for (auto &item : *block_items) {
            item->Dump();
            std::cout << ", ";
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse BlockAST" << endl;
        for (auto &item : *block_items) {
            item->Traverse();
        }
        return Data(0, 0, "", "");
    }
};

// BlockItem := Decl | Stmt
class BlockItemAST : public BaseAST {
  public:
    int mode;
    // 声明
    std::unique_ptr<BaseAST> decl;
    // 语句
    std::unique_ptr<BaseAST> stmt;

    void Dump() const override {
        cerr << "Dump BlockItemAST" << endl;
        std::cout << "BlockItemAST { ";
        if (mode == 1) {
            decl->Dump();
        } else {
            stmt->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse BlockItemAST" << endl;
        cout << endl;
        if (mode == 1) {
            decl->Traverse();
        } else {
            stmt->Traverse();
        }
        return Data(0, 0, "", "");
    }
};

// Stmt := "return" Exp ";"
// Stmt := LVal "=" Exp ";"
class StmtAST : public BaseAST {
  public:

    int mode; // 1: return 2: LVal "=" Exp
    // 返回值 exp (只有整数类型)
    std::unique_ptr<BaseAST> exp;
    // 左值
    std::unique_ptr<BaseAST> lval;

    void Dump() const override {
        cerr << "Dump StmtAST" << endl;
        std::cout << "StmtAST { ";
        if(mode == 1) exp->Dump();
        else {
            lval->Dump();
            exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse StmtAST" << endl;
        if(mode == 1) { // return
            Data x = exp->Traverse();
            if(x.mode == 1) {
                cout << "   ret " << x.value << endl;
            } else if(x.mode == 2 || x.mode == 3) {
                cout << "   ret %" << x.symbol << endl;
            }
        } else if (mode == 2) { // LVal "=" Exp
            Data x = lval->Traverse();
            if(x.mode != 2) {
              throw runtime_error("Error: LVal is not a variable");
            } 
            Data y = exp->Traverse();
            symbolTable.changeValue(x.name, to_string(y.value));
            if(y.mode == 1){
                cout << "   store " << y.value << ", @" << x.name << endl;
            } else if(y.mode == 2){
                cout << "   store @" << y.name << ", @" << x.name << endl;
            } else if(y.mode == 3) {
                cout << "   store %" << y.symbol << ", @" << x.name << endl; 
            } else {
                throw runtime_error("Error: Set vriable to a illegal variable");
            }
        }
        return Data(0, 0, "", "");
    }
};

// Exp := LOrExp
class ExpAST : public BaseAST {
  public:
    // 目前只支持一元表达式
    std::unique_ptr<BaseAST> lor_exp;

    void Dump() const override {
        cerr << "Dump ExpAST" << endl;
        std::cout << "Exp { ";
        lor_exp->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse ExpAST" << endl;
        Data x = lor_exp->Traverse();
        return x;
    }
};

// Lval := IDENT
class LValAST : public BaseAST {
  public:
    // 变量名
    std::string name;

    void Dump() const override {
        cerr << "Dump Lval" << endl;
        std::cout << "Lval { ";
        std::cout << name;
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse Lval" << endl;
        int y = gen();
        cout << "   %"<< y << " = load @" << name << endl;
        if(symbolTable.isConst(name)) {
            return Data(1, symbolTable.getConstValue(name), "", to_string(y));
        } else {
            return Data(2, symbolTable.getVirableValue(name), name, to_string(y));
        }
    }
};

// PrimaryExp := '(' Exp ')'
// PrimaryExp := Lval
// PrimaryExp := Number
class PrimaryExpAST : public BaseAST {
  public:
    int mode; // 1为exp，2为lval, 3为number

    std::unique_ptr<BaseAST> exp;

    std::unique_ptr<BaseAST> lval;

    int number;

    void Dump() const override {
        cerr << "Dump PrimaryExpAST" << endl;
        std::cout << "PrimaryExp { ";
        if (mode == 1) {
            exp->Dump();
        } else if (mode == 3) {
            std::cout << " " << number << " ";
        } else {
            lval->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse PrimaryExpAST " << endl;
        if (mode == 1) {
            Data x = exp->Traverse();
            return x;
        } else if (mode == 2) {
            Data x = lval->Traverse();
            return x;
        } else {
            Data x = Data(1, number, "", "");
            return x;
        }
    }
};

// UnaryExp := PrimaryExp
// UnaryExp := UnaryOp UnaryExp
class UnaryExpAST : public BaseAST {
  public:
    // 目前只支持一元表达式
    int mode; // 1为primary_exp，2为unary_op & unary_exp

    std::unique_ptr<BaseAST> primary_exp;

    std::string unary_op;

    std::unique_ptr<BaseAST> unary_exp;

    void Dump() const override {
        cerr << "Dump UnaryExpAST" << endl;
        std::cout << "UnaryExp { ";
        if (mode == 1) {
            primary_exp->Dump();
        } else {
            std::cout << unary_op << " ";
            unary_exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse UnaryExpAST" << endl;
        if (mode == 1) {
            Data x = primary_exp->Traverse();
            return x;
        } else {
            Data x = unary_exp->Traverse();
            if(x.mode == 1) {
                if (unary_op == "!") {
                    x.value = (x.value == 0);
                } else if (unary_op == "-") {
                    x.value = -x.value;
                }
                return x;
            } else if (x.mode == 2) {
                int y = -1;
                if (unary_op == "!") {
                    y = gen();
                    cout << "   %" << y << " = eq 0, %" << x.symbol << endl;
                    x.value = (x.value == 0);
                } else if (unary_op == "-") {
                    cout << "   %" << y << " = sub 0, %" << x.symbol << endl;
                    x.value = -x.value;
                } else {
                    return x;
                }
                return Data(3, x.value, "", to_string(y));
            } else if (x.mode == 3) {
                int y = -1;
                if (unary_op == "!") {
                    y = gen();
                    cout << "   %" << y << " = eq 0, %" << x.symbol << endl;
                    x.value = (x.value == 0);
                } else if (unary_op == "-") {
                    cout << "   %" << y << " = sub 0, %" << x.symbol << endl;
                    x.value = -x.value;
                } else {
                    return x;
                }
                return Data(3, x.value, "", to_string(y));
            }
        }
    }
};

// MulExp := UnaryExp
// MulExp := MulExp ('*' | '/' | '%') UnaryExp
class MulExpAST : public BaseAST {
  public:
    int mode; // 1为unary_exp，2为mul_exp
    std::unique_ptr<BaseAST> unary_exp;
    string op;
    std::unique_ptr<BaseAST> mul_exp;

    void Dump() const override {
        cerr << "Dump MulExp" << endl;
        std::cout << "MulExp { ";
        if (mode == 1) {
            unary_exp->Dump();
        } else {
            mul_exp->Dump();
            cout << " " << op << " ";
            unary_exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse MulExp" << endl;
        if (mode == 1) {
            Data x = unary_exp->Traverse();
            return x;
        } else {
            Data x = mul_exp->Traverse(), z = unary_exp->Traverse();
            int y = -1;
            if (op == "*") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value * z.value, "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = mul " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = mul " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = mul %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = mul %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = mul %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = mul %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = mul %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = mul %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to mul non-exp type");
                }
                return Data(3, x.value * z.value, "", to_string(y));
            } else if (op == "/") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value / z.value, "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = div " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = div " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = div %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = div %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = div %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = div %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = div %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = div %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to div non-exp type");
                }
                return Data(3, x.value / z.value, "", to_string(y));
            } else if (op == "%") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value % z.value, "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = rem " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = rem " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = rem %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = rem %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = rem %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = rem %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = rem %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = rem %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to rem non-exp type");
                }
                return Data(3, x.value % z.value, "", to_string(y));
            } 
        }
    }
};

// AddExp := MulExp
// AddExp := AddExp ('+' | '-') MulExp
class AddExpAST : public BaseAST {
  public:
    int mode; // 1为mul_exp，2为add_exp
    std::unique_ptr<BaseAST> mul_exp;
    string op;
    std::unique_ptr<BaseAST> add_exp;

    void Dump() const override {
        cerr << "Dump AddExpAST" << endl;
        std::cout << "AddExp { ";
        if (mode == 1) {
            mul_exp->Dump();
        } else {
            add_exp->Dump();
            cout << " " << op << " ";
            mul_exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse AddExp" << endl;
        if (mode == 1) {
            Data x = mul_exp->Traverse();
            return x;
        } else {
            Data x = add_exp->Traverse(), z = mul_exp->Traverse();
            int y = -1;
            if(op == "+") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value + z.value, "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = add " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = add " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = add %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = add %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = add %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = add %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = add %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = add %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to add non-exp type");
                }
                return Data(3, x.value + z.value, "", to_string(y));
            } else if(op == "-") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value - z.value, "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = sub " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = sub " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = sub %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = sub %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = sub %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = sub %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = sub %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = sub %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to sub non-exp type");
                }
                return Data(3, x.value - z.value, "", to_string(y));
            }
        }
    }
};

// RelExp := AddExp
// RelExp := RelExp ('<' | '>' | '<=' | '>=') AddExp
class RelExpAST : public BaseAST {
  public:
    int mode; // 1为add_exp，2为rel_exp
    std::unique_ptr<BaseAST> add_exp;
    string op;
    std::unique_ptr<BaseAST> rel_exp;

    void Dump() const override {
        cerr << "Dump RelExpAST" << endl;
        std::cout << "RelExp { ";
        if (mode == 1) {
            add_exp->Dump();
        } else {
            rel_exp->Dump();
            cout << " " << op << " ";
            add_exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse RelExp" << endl;
        if (mode == 1) {
            Data x = add_exp->Traverse();
            return x;
        } else {
            Data x = rel_exp->Traverse(), z = add_exp->Traverse();
            int y = -1;
            if(op == "<") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value < z.value, "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = lt " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = lt " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = lt %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = lt %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = lt %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = lt %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = lt %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = lt %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value < z.value), "", to_string(y));
            } else if(op == ">") { 
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value > z.value, "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = gt " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = gt " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = gt %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = gt %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = gt %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = gt %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = gt %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = gt %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value > z.value), "", to_string(y));
            } else if(op == "<=") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value <= z.value), "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = le " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = le " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = le %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = le %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = le %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = le %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = le %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = le %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value <= z.value), "", to_string(y));
            } else {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value >= z.value), "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ge " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = ge " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = ge %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = ge %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = ge %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = ge %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = ge %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = ge %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value >= z.value), "", to_string(y));
            }
        }
    }
};

// EqExp := RelExp
// EqExp := EqExp ('==' | '!=') RelExp
class EqExpAST : public BaseAST {
  public:
    int mode; // 1为rel_exp，2为eq_exp
    std::unique_ptr<BaseAST> rel_exp;
    string op;
    std::unique_ptr<BaseAST> eq_exp;

    void Dump() const override {
        cerr << "Dump EqExpAST" << endl;
        std::cout << "EqExp { ";
        if (mode == 1) {
            rel_exp->Dump();
        } else {
            eq_exp->Dump();
            cout << " " << op << " ";
            rel_exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse EqExp" << endl;
        if (mode == 1) {
            Data x = rel_exp->Traverse();
            return x;
        } else {
            Data x = eq_exp->Traverse(), z = rel_exp->Traverse();
            int y = -1;
            if(op == "==") {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value == z.value), "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = eq " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = eq " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = eq %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = eq %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = eq %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = eq %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = eq %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = eq %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value == z.value), "", to_string(y));
            } else {
                if(x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value != z.value), "", "");
                } else if(x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ne " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 1 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = ne " << x.value << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = ne %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 2 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = ne %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 2 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = ne %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 1) {
                  y = gen();
                  cout << "   %" << y << " = ne %" << x.symbol << ", " << z.value << endl;
                } else if(x.mode == 3 && z.mode == 2) {
                  y = gen();
                  cout << "   %" << y << " = ne %" << x.symbol << ", %" << z.symbol << endl;
                } else if(x.mode == 3 && z.mode == 3) {
                  y = gen();
                  cout << "   %" << y << " = ne %" << x.symbol << ", %" << z.symbol << endl;
                } else {
                  throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value != z.value), "", to_string(y));
            }
        }
    }
};

// LAndExp := EqExp
// LAndExp := LAndExp '&&' EqExp
class LAndExpAST : public BaseAST {
  public:
    int mode; // 1为eq_exp，2为land_exp
    std::unique_ptr<BaseAST> eq_exp;
    string op;
    std::unique_ptr<BaseAST> land_exp;

    void Dump() const override {
        cerr << "Dump LAndExpAST" << endl;
        std::cout << "LAndExp { ";
        if (mode == 1) {
            eq_exp->Dump();
        } else {
            land_exp->Dump();
            cout << " " << op << " ";
            eq_exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse LAndExp" << endl;
        if (mode == 1) {
            Data x = eq_exp->Traverse();
            return x;
        } else {
            Data x = land_exp->Traverse(), z = eq_exp->Traverse();
            if(x.mode == 1 && z.mode == 1) {
                return Data(1, (x.value && z.value), "", "");
            } else if(x.mode == 1 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else if(x.mode == 1 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else if(x.mode == 2 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else if(x.mode == 2 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else if(x.mode == 2 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else if(x.mode == 3 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else if(x.mode == 3 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else if(x.mode == 3 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value&&z.value), "", to_string(y));
            } else {
                throw runtime_error("Error: try to && non-exp type");
            }
        }
    }
};

// LOrExp := LAndExp
// LOrExp := LOrExp '||' LAndExp
class LOrExpAST : public BaseAST {
  public:
    int mode; // 1为land_exp，2为lor_exp
    std::unique_ptr<BaseAST> land_exp;
    string op;
    std::unique_ptr<BaseAST> lor_exp;

    void Dump() const override {
        cerr << "Dump LOrExpAST" << endl;
        std::cout << "LOrExp { ";
        if (mode == 1) {
            land_exp->Dump();
        } else {
            lor_exp->Dump();
            cout << " " << op << " ";
            land_exp->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse LOrExp" << endl;
        if (mode == 1) {
            Data x = land_exp->Traverse();
            return x;
        } else {
            Data x = lor_exp->Traverse(), z = land_exp->Traverse();
            if(x.mode == 1 && z.mode == 1) {
                return Data(1, (x.value || z.value), "", "");
            } else if(x.mode == 1 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else if(x.mode == 1 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else if(x.mode == 2 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else if(x.mode == 2 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else if(x.mode == 2 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else if(x.mode == 3 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else if(x.mode == 3 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else if(x.mode == 3 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value||z.value), "", to_string(y));
            } else {
                throw runtime_error("Error: try to || non-exp type");
            }
        }
    }
};

// ConstExp := Exp
class ConstExpAST : public BaseAST {
  public:
    std::unique_ptr<BaseAST> exp;

    void Dump() const override {
        cerr << "Dump ConstExp" << endl;
        std::cout << "ConstExp { ";
        exp->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse ConstExp" << endl;
        Data x = exp->Traverse();
        return x;
    }
};

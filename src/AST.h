#pragma once

#include <iostream>
#include <memory>
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
        if (table.find(name) != table.end()) {
            return false;
        }
        // 插入新符号
        table[name] = value;
        return true;
    }

    // 插入新符号，如果符号已经存在，返回 false，否则返回 true
    bool insertVirableSymbol(const std::string &name, std::string value) {
        // 如果符号已经存在，返回 false
        if (table.find(name) != table.end()) {
            return false;
        }
        // 插入新符号
        table[name] = value;
        return true;
    }

    bool isConst(const std::string &name) const {
        auto iter = table.find(name);
        if (iter == table.end()) {
            throw std::runtime_error("Symbol not found: " + name);
        }
    //    if (iter->second[0] == '%') {
    //        return false;
    //    }
        return true;
    }

    bool isVirable(const std::string &name) const {
        auto iter = table.find(name);
        if (iter == table.end()) {
            throw std::runtime_error("Symbol not found: " + name);
        }
        return false;
    }

    // 获取符号的值，如果符号不存在，抛出异常
    std::string getSymbol(const std::string &name) const {
        auto iter = table.find(name);
        if (iter == table.end()) {
            throw std::runtime_error("Symbol not found: " + name);
        }
        return iter->second;
    }

  private:
    std::unordered_map<std::string, std::string> table;
};

extern SymbolTable symbolTable;

// 发现遍历 AST 的时候返回值需要一个数据结构。先这么定义着
struct Data {

    // mode = 1 表示返回的是表达式的数值，且此时为常量
    // mode = 2 表示返回的是表达式的变量符号字符串（实际为%+数） mode = -1
    // 表示暂无返回内容。mode = 1 时 value 有效，mode = 2 时 symbol 有效

    Data(int mode, int value, string symbol)
        : mode(mode), value(value), symbol(symbol) {}

    int mode;
    int value;
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
        return Data(-1, 0, "");
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
        return Data(-1, 0, "");
    }
};

// Decl := ConstDecl
class DeclAST : public BaseAST {
  public:
    // 常量声明
    std::unique_ptr<BaseAST> const_decl;

    void Dump() const override {
        cerr << "Dump DeclAST" << endl;
        std::cout << "DeclAST { ";
        const_decl->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse DeclAST" << endl;
        const_decl->Traverse();
        return Data(-1, 0, "");
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
        return Data(-1, 0, "");
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
        /*    cerr << "Traverse BtypeAST" << endl;
            if (btype == "int") {
                cout << "i32 ";
            } else {
                // TODO
            }
            return -1;  */
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
         symbolTable.insertConstSymbol(const_name, to_string(x.value));
        //  cout << "Insert" << const_name << " as const number" << x.value << endl;
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
        Data d= const_exp->Traverse();
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
        return Data(-1, 0, "");
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
        return Data(-1, 0, "");
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
        if (mode == 1) {
            decl->Traverse();
        } else {
            stmt->Traverse();
        }
        return Data(-1, 0, "");
    }
};

// Stmt := "return" Exp ";"
class StmtAST : public BaseAST {
  public:
    // 返回值 exp (只有整数类型)
    std::unique_ptr<BaseAST> exp;

    void Dump() const override {
        cerr << "Dump StmtAST" << endl;
        std::cout << "StmtAST { ";
        exp->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse StmtAST" << endl;
        Data x = exp->Traverse();
        if(x.mode == 1) {
            cout << "   ret " << x.value << endl;
        } else if(x.mode == 2) {
            cout << "   ret " << x.symbol << endl;
        }
        // cout << "   ret  %" << x << endl;
        cout << endl;
        return x;
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
       // string symbol = symbolTable.getSymbol(name);

        //int x = stoi(symbol.substr(1));
        // cout << " get " << name << "from table :"  << endl;
        if(symbolTable.isConst(name)) {
            string s = symbolTable.getSymbol(name);
            // cout << s << endl;
            return Data(1, stoi(s), s);
        } else {
            string s = symbolTable.getSymbol(name);
            // cout << s << endl;
            return Data(2, 0, s);
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
        } else if (mode == 3) {
            Data x = Data(1, number, "");
            // cout << "   %" << x << " = add 0, " << number << endl;
            return x;
        } else {
            Data x = lval->Traverse();
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
            int y = -1;
            if(x.mode == 1) {
                 if (unary_op == "!") {
                    x.value = (x.value == 0);
                } else if (unary_op == "-") {
                    x.value = -x.value;
                }
            } else if(x.mode == 2){
               // TODO: 
            } else {
              cerr << " ERROR: UnaryExpAST x.mode == 3" << endl;
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
            if(x.mode == 1 && z.mode == 1) {
                if (op == "*") {
                    y = x.value * z.value;
                } else if (op == "/") {
                    y = x.value / z.value;
                } else if (op == "%") {
                    y = x.value % z.value;
                }
                return Data(1, y, "");
            } else {
                throw std::runtime_error("try to modify const" + x.mode);
            }
         /*  if (op == "*") {
                y = gen();
                cout << "   %" << y << " = mul %" << x << ", %" << z << endl;
            } else if (op == "/") {
                y = gen();
                cout << "   %" << y << " = div %" << x << ", %" << z << endl;
            } else if (op == "%") {
                y = gen();
                cout << "   %" << y << " = rem %" << x << ", %" << z << endl;
            }*/
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
            if(x.mode == 1 && z.mode == 1) {
                if (op == "+") {
                    y = x.value + z.value;
                } else if (op == "-") {
                    y = x.value - z.value;
                }
                return Data(1, y, "");
            } else {
                throw std::runtime_error("try to modify const" + x.mode);
            }
         /*   if (op == "+") {
                y = gen();
                cout << "   %" << y << " = add %" << x << ", %" << z << endl;
            } else if (op == "-") {
                y = gen();
                cout << "   %" << y << " = sub %" << x << ", %" << z << endl;
            }
            return y;  */
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
            if(x.mode == 1 && z.mode == 1) {
                if (op == "<") {
                    y = (x.value < z.value);
                } else if (op == ">") {
                    y = x.value > z.value;
                } else if (op == "<=") {
                    y = x.value <= z.value;
                } else if (op == ">=") {
                    y = x.value >= z.value;
                }
                return Data(1, y, "");
            } else {
                throw std::runtime_error("try to modify const" + x.mode);
            }
      /*    if (op == "<") {
                y = gen();
                cout << "   %" << y << " = lt %" << x << ", %" << z << endl;
            } else if (op == ">") {
                y = gen();
                cout << "   %" << y << " = gt %" << x << ", %" << z << endl;
            } else if (op == "<=") {
                y = gen();
                cout << "   %" << y << " = le %" << x << ", %" << z << endl;
            } else if (op == ">=") {
                y = gen();
                cout << "   %" << y << " = ge %" << x << ", %" << z << endl;
            }  
            return y;   */
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
            if(x.mode == 1 && z.mode == 1) {
                if (op == "==") {
                    y = x.value == z.value;
                } else if (op == "!=") {
                    y = x.value != z.value;
                }
                return Data(1, y, "");
            } else {
                throw std::runtime_error("try to modify const" + x.mode);
            }
      /*     if (op == "==") {
                y = gen();
                cout << "   %" << y << " = eq %" << x << ", %" << z << endl;
            } else if (op == "!=") {
                y = gen();
                cout << "   %" << y << " = ne %" << x << ", %" << z << endl;
            }
            return y;   */
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
            int y = -1;
            if(x.mode == 1 && z.mode == 1) {
                if (op == "&&") {
                    y = x.value && z.value;
                }
                return Data(1, y, "");
            } else {
                throw std::runtime_error("try to modify const" + x.mode);
            }
           /* if (op == "&&") {
                y = gen();
                cout << "   %" << y << " = and %" << x << ", %" << z << endl;
            }
            return y; */
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
            int y = -1;
            if(x.mode == 1 && z.mode == 1) {
                if (op == "||") {
                    y = x.value || z.value;
                }
                return Data(1, y, "");
            } else {
                throw std::runtime_error("try to modify const" + x.mode);
            }

         /*   if (op == "||") {
                y = gen();
                cout << "   %" << y << " = or %" << x << ", %" << z << endl;
            }  */
            // return y;
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

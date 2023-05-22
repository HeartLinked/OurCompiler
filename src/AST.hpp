#pragma once

#include "DsDef.hpp"
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

extern int cnt;

int gen();
char gen2();
char ifGen3();
char whileGen4();
char breakGen5();
char entrygen();
string genLabel(string s);
bool hasDuplicateElements(const std::vector<string> &vec);

extern stack<BlockSymbolTable *> symbolTableStack;
extern stack<string> whileLevelsStack;
extern paramentsTable paraments;
extern mapTable maptable;
extern functionTable functiontable;

// CompUnit := FuncDef
// CompUnit := CompUnit2
class CompUnitAST : public BaseAST {
  public:
    // 函数定义
    int mode;
    std::unique_ptr<BaseAST> func_def;
    std::unique_ptr<BaseAST> comp_unit2;

    void Dump() const override {
        cerr << "Dump CompUnitAST" << endl;
        std::cout << "CompUnitAST { ";
        if (mode == 1)
            func_def->Dump();
        else
            comp_unit2->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse CompUnitAST" << endl;
        if (mode == 1)
            func_def->Traverse();
        else
            comp_unit2->Traverse();
        return Data(0, 0, "", "");
    }
};

// CompUnit2 := FuncDef FuncDef
// CompUnit2 := CompUnit2 FuncDef
class CompUnit2AST : public BaseAST {
  public:
    // 函数定义
    int mode;
    std::unique_ptr<BaseAST> comp_unit2;
    std::unique_ptr<BaseAST> func_def1;
    std::unique_ptr<BaseAST> func_def2;

    void Dump() const override {
        cerr << "Dump CompUnitAST" << endl;
        std::cout << "CompUnitAST { ";
        if (mode == 1) {
            func_def1->Dump();
            func_def2->Dump();
        } else {
            comp_unit2->Dump();
            func_def1->Dump();
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse CompUnitAST" << endl;
        if (mode == 1) {
            func_def1->Traverse();
            func_def2->Traverse();
        } else {
            comp_unit2->Traverse();
            func_def1->Traverse();
        }
        return Data(0, 0, "", "");
    }
};

// FuncDef := FuncType IDENT '(' ')' Block
// FuncDef := FuncType IDENT '(' FuncFParams ')' Block
class FuncDefAST : public BaseAST {
  public:
    int mode;
    // 函数返回值类型
    std::unique_ptr<BaseAST> func_type;
    // 函数名
    std::string func_name;
    // 函数内目前只有一个入口基本块
    std::unique_ptr<BaseAST> func_block;

    std::unique_ptr<BaseAST> func_fparams;

    void Dump() const override {
        cerr << "Dump FuncDefAST" << endl;
        std::cout << "FuncDefAST { ";
        func_type->Dump();
        std::cout << ", " << func_name << ", ";
        if (mode == 1) {
            std::cout << "(), ";
        } else if (mode == 2) {
            std::cout << "(";
            func_fparams->Dump();
            std::cout << ") ";
        }
        func_block->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse FuncDefAST" << endl;
        if (mode == 1) {
            cout << "fun @" << func_name << "(): ";
        } else if (mode == 2) {
            cout << "fun @" << func_name << "(";
            func_fparams->Traverse();
            cout << "): ";
        }
        Data type = func_type->Traverse();
        cout << "{" << endl;
        func_block->Traverse();
        if (type.mode == -1)
            cout << "   ret" << endl;
        cout << "}" << endl << endl;
        return Data(0, 0, "", "");
    }
};

// FuncFParams := FuncFParam
// FuncFParams := FuncFParam ',' FuncFParams
class FuncFParamsAST : public BaseAST {
  public:
    // 函数参数
    vector<unique_ptr<BaseAST>> func_fparams = vector<unique_ptr<BaseAST>>();
    void Dump() const override {
        cerr << "Dump FuncFParamsAST" << endl;
        std::cout << "FuncFParamsAST { ";
        for (auto &func_fparam : func_fparams) {
            func_fparam->Dump();
            std::cout << ", ";
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse FuncFParamsAST" << endl;
        for (auto it = func_fparams.begin(); it != func_fparams.end(); ++it) {
            (*it)->Traverse();
            if (it != func_fparams.end() - 1) {
                cout << ", ";
            }
        }
        return Data(0, 0, "", "");
    }
};

// FuncFParam := BType IDENT
class FuncFParamAST : public BaseAST {
  public:
    // 参数类型
    std::unique_ptr<BaseAST> btype;
    // 参数名
    std::string param_name;

    void Dump() const override {
        cerr << "Dump FuncFParamAST" << endl;
        std::cout << "FuncFParamAST { ";
        btype->Dump();
        std::cout << ", " << param_name << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse FuncFParamAST" << endl;
        Data type = btype->Traverse();
        if (paraments.valid == false)
            paraments.valid = true;
        paraments.paraments.push_back(param_name);
        if (hasDuplicateElements(paraments.paraments)) {
            throw runtime_error("Duplicate parameter name");
        }
        cout << "%" << param_name << ": i32";
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
        if (mode == 1)
            const_decl->Dump();
        else
            var_decl->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse DeclAST" << endl;
        if (mode == 1)
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
        for (auto it = const_defs->begin(); it != const_defs->end(); ++it) {
            (*it)->Dump();
            if (it != std::prev(const_defs->end())) {
                std::cout << ", ";
            }
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
        // const_name = genLabel(const_name);
        std::cout << const_name << ", ";
        const_init_val->Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse ConstDef" << endl;
        Data x = const_init_val->Traverse();
        BlockSymbolTable *t = symbolTableStack.top();
        if (t->insertConstSymbol(const_name, to_string(x.value))) {
            //  cerr << "Insert const " << const_name << " as const number " <<
            //  x.value << endl;
        } else {
            cerr << "Error: const " << const_name << " has been defined"
                 << endl;
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
        for (auto it = var_defs->begin(); it != var_defs->end(); ++it) {
            (*it)->Dump();
            if (it != std::prev(var_defs->end())) {
                std::cout << ", ";
            }
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
        if (mode == 1) { // int a;
            BlockSymbolTable *t = symbolTableStack.top();
            if (t->insertVirableSymbol(var_name, "0")) {
            } else {
                throw runtime_error("Error: redefined variable " + var_name);
            }
            cout << "   @" << var_name << " = alloc i32" << endl;
            cout << "   store 0, @" << var_name << endl;
            return Data(0, 0, "", "");
        } else { // int a = x + 1;
            Data d = init_val->Traverse();
            BlockSymbolTable *t = symbolTableStack.top();
            if (t->insertVirableSymbol(var_name, to_string(d.value))) {
                // cerr << "Insert" << var_name << " as variale" << endl;
            } else {
                throw runtime_error("Error: redefined variable " + var_name);
            }
            cout << "   @" << var_name << " = alloc i32" << endl;
            if (d.mode == 1) {
                cout << "   store " << d.value << ", @" << var_name << endl;
            } else if (d.mode == 2) {
                cout << "   store @" << d.name << ", @" << var_name << endl;
            } else if (d.mode == 3) {
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
            return Data(0, 0, "", "");
        } else {
            return Data(-1, 0, "", "");
        }
    }
};

// Block := '{' {BlockItem} '}'
class BlockAST : public BaseAST {
  public:
    std::unique_ptr<vector<unique_ptr<BaseAST>>> block_items;

    void Dump() const override {
        cerr << "Dump BlockAST" << endl;
        std::cout << "BlockAST { ";
        if (block_items == nullptr) {
            std::cout << " }";
            return;
        }
        for (auto it = block_items->begin(); it != block_items->end(); ++it) {
            (*it)->Dump();
            if (it != std::prev(block_items->end())) {
                std::cout << ", ";
            }
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        string t = "";
        cerr << "Traverse BlockAST" << endl;
        BlockSymbolTable *blockSymbolTable = new BlockSymbolTable();
        if (!symbolTableStack.empty()) {
            blockSymbolTable->father = symbolTableStack.top();
            //  t = string("block") + gen2();
            // cout << "---------enter " << t << "----------" << endl;
        } else {
            cout << "%entry_" << entrygen() << ":" << endl;
            // cout << "---------enter entry----------" << endl;
        }

        if (paraments.valid) {
            maptable.valid = true;
            for (auto &p : paraments.paraments) {
                string p1 = genLabel(p);
                maptable.insert(p, p1);
                if (blockSymbolTable->insertVirableSymbol(p1, "0")) {
                    // cerr << "Insert" << p1 << " as variale" << endl;
                } else {
                    throw runtime_error("Error: redefined variable " + p1);
                }
                cout << "   @" << p1 << " = alloc i32" << endl;
                cout << "   store %" << p1 << ", @" << p1 << endl;
            }
            paraments.paraments.clear();
            paraments.valid = false;
        }

        if (block_items == nullptr) {
            return Data(0, 0, "", "");
        }
        symbolTableStack.push(blockSymbolTable);
        for (auto &item : *block_items) {
            item->Traverse();
        }
        symbolTableStack.pop();
        delete blockSymbolTable;
        maptable.valid = false;
        // if(t != "") cout << "---------end " << t << "----------" << endl;
        // else cout << "---------end entry------------" << endl;
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
// Stmt := Exp ";"
// Stmt := ";"
// Stmt := Block
// Stmt := "if" "(" Exp ")" Stmt ["else" Stmt]
// Stmt := "while" "(" Exp ")" Stmt
// Stmt := "break" ";"
// Stmt := "continue" ";"
class StmtAST : public BaseAST {
  public:
    // 1: return 2: LVal "=" Exp 3: Exp 4: ";" 5: Block
    int mode; // 6: if 7: if else 8: while 9: break 10: continue
    // 返回值 exp (只有整数类型)
    std::unique_ptr<BaseAST> exp;
    // 左值
    std::unique_ptr<BaseAST> lval;
    // 语句块
    std::unique_ptr<BaseAST> block;
    // if 语句
    std::unique_ptr<BaseAST> if_stmt;
    mutable string if_label = "";
    // else 语句
    std::unique_ptr<BaseAST> else_stmt;
    // while 语句
    std::unique_ptr<BaseAST> while_stmt;
    mutable string while_label = "";

    void Dump() const override {
        cerr << "Dump StmtAST" << endl;
        std::cout << "StmtAST { ";
        if (mode == 1)
            exp->Dump();
        else if (mode == 2) {
            lval->Dump();
            exp->Dump();
        } else if (mode == 3) {
            exp->Dump();
        } else if (mode == 4) {
            std::cout << ";";
        } else if (mode == 5) {
            block->Dump();
        } else if (mode == 6) {
            std::cout << "if (";
            exp->Dump();
            std::cout << ") ";
            if_stmt->Dump();
            if_label = ifGen3();
        } else if (mode == 7) {
            std::cout << "if (";
            exp->Dump();
            std::cout << ") ";
            if_stmt->Dump();
            if_label = ifGen3();
            std::cout << " else ";
            else_stmt->Dump();
        } else if (mode == 8) {
            std::cout << "while (";
            exp->Dump();
            std::cout << ") ";
            while_label = whileGen4();
            while_stmt->Dump();
        } else if (mode == 9) {
            std::cout << "break;";
        } else if (mode == 10) {
            std::cout << "continue;";
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse StmtAST" << endl;
        if (mode == 1) { // return
            Data x = exp->Traverse();
            if (x.mode == 1) {
                cout << "   ret " << x.value << endl;
            } else if (x.mode == 2 || x.mode == 3) {
                cout << "   ret %" << x.symbol << endl;
            }
        } else if (mode == 2) { // LVal "=" Exp
            Data x = lval->Traverse();
            if (x.mode != 2) {
                throw runtime_error("Error: LVal is not a variable");
            }
            Data y = exp->Traverse();
            BlockSymbolTable *blockSymbolTable = symbolTableStack.top();
            blockSymbolTable->changeValue(x.name, to_string(y.value));
            if (y.mode == 1) {
                cout << "   store " << y.value << ", @" << x.name << endl;
            } else if (y.mode == 2) {
                cout << "   store @" << y.name << ", @" << x.name << endl;
            } else if (y.mode == 3) {
                cout << "   store %" << y.symbol << ", @" << x.name << endl;
            } else {
                throw runtime_error("Error: Set vriable to a illegal variable");
            }
        } else if (mode == 3) {
            exp->Traverse();
        } else if (mode == 4) {
            // do nothing
        } else if (mode == 5) {
            block->Traverse();
        } else if (mode == 6) {
            Data x = exp->Traverse();
            if (x.mode == 1) {
                cout << "   br " << x.value << ", %if_" << if_label
                     << ", %end_if_else_" << if_label << endl;
            } else if (x.mode == 2 || x.mode == 3) {
                cout << "   br %" << x.symbol << ", %if_" << if_label
                     << ", %end_if_else_" << if_label << endl;
            }
            cout << endl << "%if_" << if_label << ":" << endl;
            if_stmt->Traverse();
            cout << "   jump %end_if_else_" << if_label << endl;
            cout << endl << "%end_if_else_" << if_label << ":" << endl;
        } else if (mode == 7) {
            Data x = exp->Traverse();
            if (x.mode == 1) {
                cout << "   br " << x.value << ", %if_" << if_label
                     << ", %else_" << if_label << endl;
            } else if (x.mode == 2 || x.mode == 3) {
                cout << "   br %" << x.symbol << ", %if_" << if_label
                     << ", %else_" << if_label << endl;
            }
            cout << endl << "%if_" << if_label << ":" << endl;
            if_stmt->Traverse();
            cout << "   jump %end_if_else_" << if_label << endl;
            cout << endl << "%else_" << if_label << ":" << endl;
            else_stmt->Traverse();
            cout << "   jump %end_if_else_" << if_label << endl;
            cout << endl << "%end_if_else_" << if_label << ":" << endl;
        } else if (mode == 8) {
            whileLevelsStack.push(while_label);
            cout << "   jump %while_entry_" << while_label << endl;
            cout << endl << "%while_entry_" << while_label << ":" << endl;
            Data x = exp->Traverse();
            if (x.mode == 1) {
                cout << "   br " << x.value << ", %while_body_" << while_label
                     << ", %end_while_" << while_label << endl;
            } else if (x.mode == 2 || x.mode == 3) {
                cout << "   br %" << x.symbol << ", %while_body_" << while_label
                     << ", %end_while_" << while_label << endl;
            }
            cout << endl << "%while_body_" << while_label << ":" << endl;
            while_stmt->Traverse();
            cout << "   jump %while_entry_" << while_label << endl;
            cout << endl << "%end_while_" << while_label << ":" << endl;
            whileLevelsStack.pop();
        } else if (mode == 9) {
            if (whileLevelsStack.empty()) {
                throw runtime_error(
                    "Error: break statement is not in a while loop");
            }
            cout << "   jump %end_while_" << whileLevelsStack.top() << endl;
            cout << endl << "%Unreachable_" << breakGen5() << ":" << endl;
             
        } else if (mode == 10) {
            if (whileLevelsStack.empty()) {
                throw runtime_error(
                    "Error: continue statement is not in a while loop");
            }
            cout << "   jump %while_entry_" << whileLevelsStack.top() << endl;
            cout << endl << "%Unreachable_" << breakGen5() << ":" << endl;
             
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
    mutable std::string name;

    void Dump() const override {
        cerr << "Dump Lval" << endl;
        std::cout << "Lval { ";
        std::cout << name;
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse Lval" << endl;
        int y = gen();
        if(maptable.valid) name = maptable.get(name);
        cout << "   %" << y << " = load @" << name << endl;
        BlockSymbolTable *blockSymbolTable = symbolTableStack.top();
        if (blockSymbolTable->isConst(name)) {
            return Data(1, blockSymbolTable->getConstValue(name), "",
                        to_string(y));
        } else {
            return Data(2, blockSymbolTable->getVirableValue(name), name,
                        to_string(y));
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
// UnaryExp := IDENT '(' FuncRParams ')' 
// UnaryExp := IDENT '(' ')'
class UnaryExpAST : public BaseAST {
  public:
    int mode; // 1为primary_exp, 2为unary_op & unary_exp, 3为函数调用, 4为函数调用无参数

    std::unique_ptr<BaseAST> primary_exp;

    std::string unary_op, func_name;

    std::unique_ptr<BaseAST> unary_exp;

    std::unique_ptr<BaseAST> func_rparams;

    void Dump() const override {
        cerr << "Dump UnaryExpAST" << endl;
        std::cout << "UnaryExp { ";
        if (mode == 1) {
            primary_exp->Dump();
        } else if(mode == 2){
            std::cout << unary_op << " ";
            unary_exp->Dump();
        } else if(mode == 3){
            std::cout << func_name << " ";
            func_rparams->Dump();
        } else {
            std::cout << func_name << " ";
        }
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse UnaryExpAST" << endl;
        if (mode == 1) {
            Data x = primary_exp->Traverse();
            return x;
        } else if(mode == 2){
            Data x = unary_exp->Traverse();
            if (x.mode == 1) {
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
                    y = gen();
                    cout << "   %" << y << " = sub 0, %" << x.symbol << endl;
                    x.value = -x.value;
                } else {                                                                         
                    return x;
                }
                return Data(2, x.value, "", to_string(y));
            } else if(x.mode == 3) {
                int y = gen();
                if (unary_op == "!") {
                    cout << "   %" << y << " = eq 0, %" << x.symbol << endl;
                    x.value = (x.value == 0);
                } else if (unary_op == "-") {
                    cout << "   %" << y << " = sub 0, %" << x.symbol << endl;
                    x.value = -x.value;
                } else {                                                                         
                    return x;
                }
                return Data(2, x.value, "", to_string(y));
            } else {
                return x;
            }
        } else if (mode == 3) {
                int y = gen();
                functiontable.valid = true;
                func_rparams->Traverse();
                cout << "   %" << y << " = call @" << func_name << "(" ;
                for(int i = 0; i < functiontable.paraments.size(); i++){
                    if(i != 0) cout << ", ";
                    cout << functiontable.paraments[i];
                }
                cout << ")" << endl;
                functiontable.paraments.clear();
                functiontable.valid = false;
                return Data(3, y, "", to_string(y));   
        } else if(mode == 4){
                int y = gen();
                cout << "   %" << y << " = call @" << func_name << "()" << endl;
                return Data(3, y, "", to_string(y));   
        }
    }
};

// FuncRParams := Exp 
// FuncRParams := Exp ',' FuncRParams
class FuncRParamsAST : public BaseAST {
  public:
    int mode; // 1为exp, 2为exp, func_rparams
    std::unique_ptr<BaseAST> exp;
    std::unique_ptr<BaseAST> func_rparams;

    void Dump() const override {
        cerr << "Dump FuncRParams" << endl;
        std::cout << "FuncRParams { ";
        exp -> Dump();
        cout << ", ";
        if(mode == 2) func_rparams -> Dump();
        std::cout << " }";
    }

    Data Traverse() const override {
        cerr << "Traverse FuncRParams" << endl;
        Data x = exp->Traverse();
        if(mode == 1) {
          if(x.mode == 1) {
            functiontable.paraments.push_back(to_string(x.value));
          } else if(x.mode == 2) {
            functiontable.paraments.push_back("%" + x.symbol);
          } else if(x.mode == 3) {
            functiontable.paraments.push_back("%" + x.symbol);
          }
        } else if(mode == 2) {
          if(x.mode == 1) {
            functiontable.paraments.push_back(to_string(x.value));
          } else if(x.mode == 2) {
            functiontable.paraments.push_back("%" + x.symbol);
          } else if(x.mode == 3) {
            functiontable.paraments.push_back("%" + x.symbol);
          }
          func_rparams->Traverse();
        }
        return Data(0, 0, "", "");
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
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value * z.value, "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = mul " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = mul " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = mul %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = mul %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = mul %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = mul %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = mul %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = mul %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else {
                    throw runtime_error("Error: try to mul non-exp type");
                }
                return Data(3, x.value * z.value, "", to_string(y));
            } else if (op == "/") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value / z.value, "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = div " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = div " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = div %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = div %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = div %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = div %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = div %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = div %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else {
                    throw runtime_error("Error: try to div non-exp type");
                }
                return Data(3, x.value / z.value, "", to_string(y));
            } else if (op == "%") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value % z.value, "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = rem " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = rem " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = rem %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = rem %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = rem %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = rem %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = rem %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = rem %" << x.symbol << ", %"
                         << z.symbol << endl;
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
            if (op == "+") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value + z.value, "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = add " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = add " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = add %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = add %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = add %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = add %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = add %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = add %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else {
                    throw runtime_error("Error: try to add non-exp type");
                }
                return Data(3, x.value + z.value, "", to_string(y));
            } else if (op == "-") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value - z.value, "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = sub " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = sub " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = sub %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = sub %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = sub %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = sub %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = sub %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = sub %" << x.symbol << ", %"
                         << z.symbol << endl;
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
            if (op == "<") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value < z.value, "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = lt " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = lt " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = lt %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = lt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = lt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = lt %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = lt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = lt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else {
                    throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value < z.value), "", to_string(y));
            } else if (op == ">") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, x.value > z.value, "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = gt " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = gt " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = gt %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = gt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = gt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = gt %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = gt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = gt %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else {
                    throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value > z.value), "", to_string(y));
            } else if (op == "<=") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value <= z.value), "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = le " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = le " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = le %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = le %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = le %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = le %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = le %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = le %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else {
                    throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value <= z.value), "", to_string(y));
            } else {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value >= z.value), "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ge " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = ge " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = ge %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ge %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = ge %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = ge %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ge %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = ge %" << x.symbol << ", %"
                         << z.symbol << endl;
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
            if (op == "==") {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value == z.value), "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = eq " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = eq " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = eq %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = eq %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = eq %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = eq %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = eq %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = eq %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else {
                    throw runtime_error("Error: try to compare non-exp type");
                }
                return Data(3, (x.value == z.value), "", to_string(y));
            } else {
                if (x.mode == 1 && z.mode == 1) {
                    return Data(1, (x.value != z.value), "", "");
                } else if (x.mode == 1 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ne " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 1 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = ne " << x.value << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = ne %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 2 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ne %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 2 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = ne %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 1) {
                    y = gen();
                    cout << "   %" << y << " = ne %" << x.symbol << ", "
                         << z.value << endl;
                } else if (x.mode == 3 && z.mode == 2) {
                    y = gen();
                    cout << "   %" << y << " = ne %" << x.symbol << ", %"
                         << z.symbol << endl;
                } else if (x.mode == 3 && z.mode == 3) {
                    y = gen();
                    cout << "   %" << y << " = ne %" << x.symbol << ", %"
                         << z.symbol << endl;
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
            if (x.mode == 1 && z.mode == 1) {
                return Data(1, (x.value && z.value), "", "");
            } else if (x.mode == 1 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
            } else if (x.mode == 1 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
            } else if (x.mode == 2 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
            } else if (x.mode == 2 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
            } else if (x.mode == 2 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
            } else if (x.mode == 3 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
            } else if (x.mode == 3 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
            } else if (x.mode == 3 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = and %" << a << ", %" << b << endl;
                return Data(3, (x.value && z.value), "", to_string(y));
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
            if (x.mode == 1 && z.mode == 1) {
                return Data(1, (x.value || z.value), "", "");
            } else if (x.mode == 1 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
            } else if (x.mode == 1 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne " << x.value << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
            } else if (x.mode == 2 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
            } else if (x.mode == 2 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
            } else if (x.mode == 2 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
            } else if (x.mode == 3 && z.mode == 1) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne " << z.value << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
            } else if (x.mode == 3 && z.mode == 2) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
            } else if (x.mode == 3 && z.mode == 3) {
                int a = gen(), b = gen(), y = gen();
                cout << "   %" << a << " = ne %" << x.symbol << ", 0" << endl;
                cout << "   %" << b << " = ne %" << z.symbol << ", 0" << endl;
                cout << "   %" << y << " = or %" << a << ", %" << b << endl;
                return Data(3, (x.value || z.value), "", to_string(y));
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

#pragma once

#include <iostream>
#include <memory>
using namespace std;

extern int cnt;

int gen();

// 所有 AST 的基类
class BaseAST {
  public:
    virtual ~BaseAST() = default;

    virtual void Dump() const = 0;

    virtual int Traverse() const = 0;
};

// CompUnit := FuncDef
class CompUnitAST : public BaseAST {
  public:
    // 程序目前只由一个函数组成
    std::unique_ptr<BaseAST> func_def;

    void Dump() const override {
        std::cout << "CompUnitAST { ";
        func_def->Dump();
        std::cout << " }";
    }

    int Traverse() const override {
        // Dump();  这里疑似暂时不用输出
        cerr << "Traverse CompUnitAST" << endl;
        func_def->Traverse();
        return -1;
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
        std::cout << "FuncDefAST { ";
        func_type->Dump();
        std::cout << ", " << func_name << ", ";
        // std::cout << "arglist: " << arglist << std::endl;
        func_block->Dump();
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse FuncDefAST" << endl;
        cout << "fun @" << func_name << "(): ";
        func_type->Traverse();
        cout << "{" << endl;
        func_block->Traverse();
        cout << "}" << endl;
        return -1;
    }

    // FuncDef := Type Ident '(' ArgList ')' '{' FuncBody '}'
    // 函数参数列表
    // std::vector<std::pair<std::string, std::string>> arglist;
    // 函数体
    // std::unique_ptr<BaseAST> funcbody;
};

class FuncTypeAST : public BaseAST {
  public:
    // 函数返回值类型
    std::string type;

    void Dump() const override {
        std::cout << "FuncTypeAST { ";
        std::cout << type;
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse FuncTypeAST" << endl;
        if (type == "int") {
            cout << "i32 ";
        } else {
            // TODO
        }
        return -1;
    }
};

// Block := '{' Stmt* '}'
// Block := '{' Stmt '}'
class BlockAST : public BaseAST {
  public:
    // 块内的语句，目前只有一条返回指令
    std::unique_ptr<BaseAST> stmts;

    void Dump() const override {
        std::cout << "BlockAST { ";
        stmts->Dump();
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse BlockAST" << endl;
        stmts->Traverse();
        return -1;
    }

    // std::vector<std::unique_ptr<BaseAST>> stmts;
};

// Stmt := "return" Number ";"
// Stmt := "return" Exp ";"
class StmtAST : public BaseAST {
  public:
    // // 返回值, 目前只有 int
    // // 类型，由于右侧有两种合适的匹配，设计一个mode来区分，1为number，2为exp
    // int mode;
    // // mode = 1时，返回值为number，stmt_ret为返回值
    // int stmt_ret;
    // // mode = 2时，返回值为exp，exp为返回值
    std::unique_ptr<BaseAST> exp;

    void Dump() const override {
        std::cout << "StmtAST { ";
        // if (mode == 1) {
        //     std::cout << " " << stmt_ret << " ";
        // } else {
        exp->Dump();
        // }
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse StmtAST" << endl;

        // if (mode == 1) {
        //     cout << stmt_ret;
        // } else {
        int x = exp->Traverse();
        // }
        // cout << stmt_ret;
        cout << "   ret  %" << x << endl;
        cout << endl;
        return -1;
    }
};

// Exp := UnaryExp
class ExpAST : public BaseAST {
  public:
    // 目前只支持一元表达式
    std::unique_ptr<BaseAST> unary_exp;

    void Dump() const override {
        std::cout << "Exp { ";
        unary_exp->Dump();
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse ExpAST" << endl;
        int x = unary_exp->Traverse();
        return x;
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
        std::cout << "UnaryExp { ";
        if (mode == 1) {
            primary_exp->Dump();
        } else {
            std::cout << unary_op << " ";
            unary_exp->Dump();
        }
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse UnaryExpAST" << endl;
        if (mode == 1) {
            int x = primary_exp->Traverse();
            return x;
        } else {
            int x = unary_exp->Traverse(), y = -1;
            if (unary_op == "!") {
                y = gen();
                cout << "   %" << y << " = eq 0, %" << x << endl;
            } else if (unary_op == "-") {
                y = gen();
                cout << "   %" << y << " = sub 0, %" << x << endl;
            }
            if (y == -1)
                return x;
            else
                return y;
        }
    }
};

// PrimaryExp := '(' Exp ')'
// PrimaryExp := Number
class PrimaryExpAST : public BaseAST {
  public:
    int mode; // 1为exp，2为number

    std::unique_ptr<BaseAST> exp;

    int number;

    void Dump() const override {
        std::cout << "PrimaryExp { ";
        if (mode == 1) {
            exp->Dump();
        } else {
            std::cout << " " << number << " ";
        }
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse PrimaryExpAST " << endl;
        if (mode == 1) {
            int x = exp->Traverse();
            return x;
        } else {
            int x = gen();
            cout << "   %" << x << " = add 0, " << number << endl;
            return x;
        }
    }
};

/*
// FuncBody := (Decl | Stmt)*
class FuncBodyAST : public BaseAST {
  public:
    // 函数体内的声明
    std::vector<std::unique_ptr<BaseAST>> decls;
    // 函数体内的语句
    std::vector<std::unique_ptr<BaseAST>> stmts;
};

// ArgList := Arg (',' Arg)*
class ArgListAST : public BaseAST {
  public:
    // 函数参数列表
    std::vector<std::pair<std::string, std::string>> arglist;
};

// Arg := Type IDENT
class ArgAST : public BaseAST {
  public:
    // 参数类型
    std::string type;
    // 参数名
    std::string ident;
};
*/

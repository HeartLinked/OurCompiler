#pragma once

#include <iostream>
using namespace std;

// 所有 AST 的基类
class BaseAST {
  public:
    virtual ~BaseAST() = default;

    virtual void Dump() const = 0;

    virtual void Traverse() const = 0;
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

    void Traverse() const override {
        // Dump();  这里疑似暂时不用输出
        func_def->Traverse();
    }
};

// FuncDef := FuncType IDENT '(' ')' Block
// FuncDef := Type Ident '(' ArgList ')' '{' FuncBody '}'
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

    void Traverse() const override {
        cout << "fun @" << func_name << "(): ";
        func_type->Traverse();
        cout << "{" << endl;
        func_block->Traverse();
        cout << "}" << endl;
    }

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

    void Traverse() const override {
        if(type == "int") {
            cout << "i32 ";
        }
        else {
            // TODO
        }
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

    void Traverse() const override {
        stmts->Traverse();
    }

    // std::vector<std::unique_ptr<BaseAST>> stmts;
};

// Stmt := "return" Number ";"
class StmtAST : public BaseAST {
  public:
    // 返回值, 目前只有 int 类型
    int stmt_ret;

    void Dump() const override {
        std::cout << "StmtAST { ";
        std::cout << stmt_ret;
        std::cout << " }";
    }

    void Traverse() const override {
        cout << "   ret ";
        cout << stmt_ret;
        cout << endl;
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
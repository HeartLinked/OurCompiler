%code requires {
  #include <memory>
  #include <string>
  #include "AST.h"
}

%{

#include <iostream>
#include <memory>
#include <string>
#include "AST.h"

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;

%}

// 定义 parser 函数和错误处理函数的附加参数
%parse-param { std::unique_ptr<BaseAST> &ast }

// yylval 的定义, 我们把它定义成了一个联合体 (union)
%union {
  std::string *str_val;
  int int_val;
  BaseAST *ast_val;   // AST
}

// lexer 返回的所有 token 种类的声明
// 注意 IDENT 和 INT_CONST 会返回 token 的值, 分别对应 str_val 和 int_val
%token INT RETURN
%token <str_val> IDENT
%token <int_val> INT_CONST

// 非终结符的类型定义
%type <ast_val> FuncDef FuncType Block Stmt 
%type <int_val> Number

%%

// CompUnit := FuncDef
CompUnit
  : FuncDef {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->func_def = unique_ptr<BaseAST>($1);
    ast = move(comp_unit);
  }
  ;

// FuncDef := FuncType IDENT '(' ')' Block
FuncDef
  : FuncType IDENT '(' ')' Block {
    auto func_def = new FuncDefAST();
    func_def->func_type = unique_ptr<BaseAST>($1);
    func_def->func_name = *unique_ptr<string>($2);
    func_def->func_block = unique_ptr<BaseAST>($5);
    $$ = func_def;
  }
  ;


FuncType
  : INT {
    // cout << "INT" << endl;
    auto func_type = new FuncTypeAST();
    func_type -> type = "int";
    $$ = func_type;
  }
  ;

Block
  : '{' Stmt '}' {
    auto block = new BlockAST();
    block -> stmts = unique_ptr<BaseAST>($2);
    $$ = block;
  }
  ;

Stmt
  : RETURN Number ';' {
    auto stmt = new StmtAST();
    stmt->stmt_ret = $2;
    $$ = stmt;
  }
  ;

Number
  : INT_CONST {
    
  }
  ;

%%

// 定义错误处理函数, 其中第二个参数是错误信息, parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}

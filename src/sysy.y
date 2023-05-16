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
%type <ast_val> FuncDef FuncType Block Stmt PrimaryExp UnaryExp Exp MulExp AddExp
%type <str_val> UnaryOp
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
  :
  // : RETURN Number ';' {
  //   auto stmt = new StmtAST();
  //   stmt->stmt_ret = $2;
  //   stmt->mode = 1;
  //   $$ = stmt;
  // }
  RETURN Exp ';' {
    auto stmt = new StmtAST();
    stmt->exp = unique_ptr<BaseAST>($2);
    // stmt->mode = 2;
    $$ = stmt;
  }
  ;


Exp
  : AddExp {
    // TODO 
    auto exp = new ExpAST();
    exp -> add_exp = unique_ptr<BaseAST>($1);
    $$ = exp;
  }
  ;

PrimaryExp
  : '(' Exp ')' {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> exp = unique_ptr<BaseAST>($2);
    primary_exp -> mode = 1;
    $$ = primary_exp;
  }
  | Number {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> number = $1;
    primary_exp -> mode = 2;
    $$ = primary_exp;
  }

UnaryExp
  : PrimaryExp {
    auto unary_exp = new UnaryExpAST();
    unary_exp -> primary_exp = unique_ptr<BaseAST>($1);
    unary_exp -> mode = 1;
    $$ = unary_exp;
  }
  | UnaryOp UnaryExp{
    auto unary_exp = new UnaryExpAST();
    unary_exp -> unary_op = *($1);
    unary_exp -> unary_exp = unique_ptr<BaseAST>($2);
    unary_exp -> mode = 2;
    $$ = unary_exp;
  }

UnaryOp
  : '+' {
    $$ = new string("+");
  }
  | '-' {
    $$ = new string("-");
  } 
  | '!' {
    $$ = new string("!");
  }
  ;

MulExp
  : UnaryExp {
    auto mul_exp = new MulExpAST();
    mul_exp -> unary_exp = unique_ptr<BaseAST>($1);
    mul_exp -> mode = 1;
    $$ = mul_exp;
  }
  | MulExp '*' UnaryExp {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>($1);
    mul_exp -> mode = 2;
    mul_exp -> op = "*";
    mul_exp -> unary_exp = unique_ptr<BaseAST>($3);
    $$ = mul_exp;
  }
  | MulExp '/' UnaryExp {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>($1);
    mul_exp -> mode = 2;
    mul_exp -> op = "/";
    mul_exp -> unary_exp = unique_ptr<BaseAST>($3);
    $$ = mul_exp;
  } 
  | MulExp '%' UnaryExp {
    auto mul_exp = new MulExpAST();
    mul_exp -> mul_exp = unique_ptr<BaseAST>($1);
    mul_exp -> mode = 2;
    mul_exp -> op = "%";
    mul_exp -> unary_exp = unique_ptr<BaseAST>($3);
    $$ = mul_exp;
  }

AddExp
 : MulExp {
    auto add_exp = new AddExpAST();
    add_exp -> mul_exp = unique_ptr<BaseAST>($1);
    add_exp -> mode = 1;
    $$ = add_exp;
 }
  | AddExp '+' MulExp {
    auto add_exp = new AddExpAST();
    add_exp -> add_exp = unique_ptr<BaseAST>($1);
    add_exp -> mode = 2;
    add_exp -> op = "+";
    add_exp -> mul_exp = unique_ptr<BaseAST>($3);
    $$ = add_exp;
  }
  | AddExp '-' MulExp {
    auto add_exp = new AddExpAST();
    add_exp -> add_exp = unique_ptr<BaseAST>($1);
    add_exp -> mode = 2;
    add_exp -> op = "-";
    add_exp -> mul_exp = unique_ptr<BaseAST>($3);
    $$ = add_exp;
  }

Number
  : INT_CONST ;
%%

// 定义错误处理函数, 其中第二个参数是错误信息, parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}

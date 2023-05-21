%debug

%code requires {
  #include <memory>
  #include <string>
  #include "AST.hpp"
}

%{

#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"

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
  vector<std::unique_ptr<BaseAST>> *ast_list_val; // AST list
}

// lexer 返回的所有 token 种类的声明
// 注意 IDENT 和 INT_CONST 会返回 token 的值, 分别对应 str_val 和 int_val
%token INT RETURN AND OR EQ NE LE GE CONST IF ELSE WHILE CONTINUE BREAK
%token <str_val> IDENT
%token <int_val> INT_CONST

// 非终结符的类型定义
%type <ast_val> VarDecl VarDef InitVal LVal ConstDef FuncDef FuncType Block BlockItem Stmt PrimaryExp UnaryExp Exp MulExp AddExp LOrExp RelExp EqExp LAndExp Decl ConstDecl ConstInitVal BType ConstExp
%type <ast_val> open_statement closed_statement  
%type <ast_list_val> ConstDefList BlockItemList VarDefList 
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

Decl
  : ConstDecl{
    auto decl = new DeclAST();
    decl->const_decl = unique_ptr<BaseAST>($1);
    decl->mode = 1;
    $$ = decl;
  }
  | VarDecl {
    auto decl = new DeclAST();
    decl->var_decl = unique_ptr<BaseAST>($1);
    decl->mode = 2;
    $$ = decl;
  }
  ;

ConstDecl
  : CONST BType ConstDefList ';' {
    auto const_decl = new ConstDeclAST();
    const_decl->b_type = unique_ptr<BaseAST>($2);
    const_decl->const_defs = unique_ptr<vector<std::unique_ptr<BaseAST>>>($3);
    $$ = const_decl;
  }
  ;

// ----------------WARNING----------------------
ConstDefList
  : ConstDef {
    auto const_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    const_def_list->push_back(move(unique_ptr<BaseAST>($1)));
    $$ = const_def_list;
  }
  | ConstDef ',' ConstDefList {
    auto const_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    const_def_list->push_back(move(unique_ptr<BaseAST>($1)));
    for (auto &const_def : *$3) {
      const_def_list->push_back(move(const_def));
    }
    $$ = const_def_list;
  }
  ;

// Btype := INT
BType
  : INT {
    auto b_type = new BTypeAST();
    b_type->btype = "int";
    $$ = b_type;
  }
  ;

// ConstDef := IDENT '=' ConstInitVal
ConstDef
  : IDENT '=' ConstInitVal {
    auto const_def = new ConstDefAST();
    const_def->const_name = *unique_ptr<string>($1);
    const_def->const_init_val = unique_ptr<BaseAST>($3);
    $$ = const_def;
  }
  ;

// ConstInitVal := ConstExp
ConstInitVal
  : ConstExp {
    auto const_init_val = new ConstInitValAST();
    const_init_val->const_exp = unique_ptr<BaseAST>($1);
    $$ = const_init_val;
  }
  ;

VarDecl 
  : BType VarDefList ';' {
    auto var_decl = new VarDeclAST();
    var_decl->b_type = unique_ptr<BaseAST>($1);
    var_decl->var_defs = unique_ptr<vector<std::unique_ptr<BaseAST>>>($2);
    $$ = var_decl;
  }
  ;   

VarDefList
  : VarDef {
    auto var_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    var_def_list->push_back(move(unique_ptr<BaseAST>($1)));
    $$ = var_def_list;
  }
  | VarDef ',' VarDefList {
    auto var_def_list = new std::vector<std::unique_ptr<BaseAST>>();
    var_def_list->push_back(move(unique_ptr<BaseAST>($1)));
    for (auto &var_def : *$3) {
      var_def_list->push_back(move(var_def));
    }
    $$ = var_def_list;
  }
  ;

VarDef
  : IDENT {
    auto var_def = new VarDefAST();
    var_def->var_name = *unique_ptr<string>($1);
    var_def->mode = 1;
    $$ = var_def;
  }
  | IDENT '=' InitVal {
    auto var_def = new VarDefAST();
    var_def->var_name = *unique_ptr<string>($1);
    var_def->init_val = unique_ptr<BaseAST>($3);
    var_def->mode = 2;
    $$ = var_def;
  }
  ;

InitVal
  : Exp {
    auto init_val = new InitValAST();
    init_val->exp = unique_ptr<BaseAST>($1);
    $$ = init_val;
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
    auto func_type = new FuncTypeAST();
    func_type -> type = "int";
    $$ = func_type;
  }
  ;


Block
  : '{' BlockItemList '}' {
    auto block = new BlockAST();
    block -> block_items = unique_ptr<vector<std::unique_ptr<BaseAST>>>($2);
    $$ = block;
  }
  ;

BlockItemList 
  : BlockItem {
    auto blockitem_list = new std::vector<std::unique_ptr<BaseAST>>();
    blockitem_list -> push_back(move(unique_ptr<BaseAST>($1)));
    $$ = blockitem_list;
  }
  | BlockItem BlockItemList {
    auto blockitem_list = new std::vector<std::unique_ptr<BaseAST>>();
    blockitem_list -> push_back(move(unique_ptr<BaseAST>($1)));
    for (auto &blockitem : *$2) {
      blockitem_list -> push_back(move(blockitem));
    }
    $$ = blockitem_list;
  }
  ;

// BlockItem := Decl | Stmt
BlockItem
  : Decl {
    auto blockitem = new BlockItemAST();
    blockitem -> decl = unique_ptr<BaseAST>($1);
    blockitem -> mode = 1;
    $$ = blockitem;
  }
  | Stmt {
    auto blockitem = new BlockItemAST();
    blockitem -> stmt = unique_ptr<BaseAST>($1);
    blockitem -> mode = 2;
    $$ = blockitem;
  }
  ;

Stmt
  : open_statement{ 
  }
  | closed_statement {
  }

 open_statement
  : IF '(' Exp ')' Stmt{
    auto stmt = new StmtAST();
    stmt->mode = 6;
    stmt->exp = unique_ptr<BaseAST>($3); 
    stmt->if_stmt = unique_ptr<BaseAST>($5);
    $$ = stmt;
  }
  | IF '(' Exp ')' closed_statement ELSE open_statement{
    auto stmt = new StmtAST();
    stmt->mode = 7;
    stmt->exp = unique_ptr<BaseAST>($3); 
    stmt->if_stmt = unique_ptr<BaseAST>($5);
    stmt->else_stmt = unique_ptr<BaseAST>($7);
    $$ = stmt;
  }
  | WHILE '(' Exp ')' open_statement {
    auto stmt = new StmtAST();
    stmt->mode = 8;
    stmt->exp = unique_ptr<BaseAST>($3);
    stmt->while_stmt = unique_ptr<BaseAST>($5);
    $$ = stmt;
  }

closed_statement
  : IF '(' Exp ')' closed_statement ELSE closed_statement{
    auto stmt = new StmtAST();
    stmt->mode = 7;
    stmt->exp = unique_ptr<BaseAST>($3);
    stmt->if_stmt = unique_ptr<BaseAST>($5);
    stmt->else_stmt = unique_ptr<BaseAST>($7);
    $$ = stmt; 
  }
  | WHILE '(' Exp ')' closed_statement {
    auto stmt = new StmtAST();
    stmt->mode = 8;
    stmt->exp = unique_ptr<BaseAST>($3);
    stmt->while_stmt = unique_ptr<BaseAST>($5);
    $$ = stmt;
  }
  | LVal '=' Exp ';' {
    auto stmt = new StmtAST();
    stmt->mode = 2;
    stmt->lval = unique_ptr<BaseAST>($1);
    stmt->exp = unique_ptr<BaseAST>($3);
    $$ = stmt;
  }
  | Exp ';' {
    auto stmt = new StmtAST();
    stmt->mode = 3;
    stmt->exp = unique_ptr<BaseAST>($1);
    $$ = stmt;
  }
  | ';'{
    auto stmt = new StmtAST();
    stmt->mode = 4;
    $$ = stmt;
  }
  | Block {
    auto stmt = new StmtAST();
    stmt->mode = 5;
    stmt->block = unique_ptr<BaseAST>($1);
    $$ = stmt;
  }
  | RETURN Exp ';' {
    auto stmt = new StmtAST();
    stmt->exp = unique_ptr<BaseAST>($2);
    stmt->mode = 1;
    $$ = stmt;
  }
  ;

Exp
  : LOrExp {
    auto exp = new ExpAST();
    exp -> lor_exp = unique_ptr<BaseAST>($1);
    $$ = exp;
  }
  ;

LVal
  : IDENT {
    auto lval = new LValAST();
    lval -> name = *unique_ptr<string>($1);
    $$ = lval;
  }


PrimaryExp
  : '(' Exp ')' {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> exp = unique_ptr<BaseAST>($2);
    primary_exp -> mode = 1;
    $$ = primary_exp;
  }
  | LVal {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> lval = unique_ptr<BaseAST>($1);
    primary_exp -> mode = 2;
    $$ = primary_exp;
  }
  | Number {
    auto primary_exp = new PrimaryExpAST();
    primary_exp -> number = $1;
    primary_exp -> mode = 3;
    $$ = primary_exp;
  }
  ;

Number
  : INT_CONST 
  ;

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
  ;

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
  ;

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
  ;

RelExp
  : AddExp {
    auto rel_exp = new RelExpAST();
    rel_exp -> add_exp = unique_ptr<BaseAST>($1);
    rel_exp -> mode = 1;
    $$ = rel_exp;
  }
  | RelExp '<' AddExp {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>($1);
    rel_exp -> mode = 2;
    rel_exp -> op = "<";
    rel_exp -> add_exp = unique_ptr<BaseAST>($3);
    $$ = rel_exp;
  }
  | RelExp '>' AddExp {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>($1);
    rel_exp -> mode = 2;
    rel_exp -> op = ">";
    rel_exp -> add_exp = unique_ptr<BaseAST>($3);
    $$ = rel_exp;
  }
  | RelExp LE AddExp {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>($1);
    rel_exp -> mode = 2;
    rel_exp -> op = "<=";
    rel_exp -> add_exp = unique_ptr<BaseAST>($3);
    $$ = rel_exp;
  }
  | RelExp GE AddExp {
    auto rel_exp = new RelExpAST();
    rel_exp -> rel_exp = unique_ptr<BaseAST>($1);
    rel_exp -> mode = 2;
    rel_exp -> op = ">=";
    rel_exp -> add_exp = unique_ptr<BaseAST>($3);
    $$ = rel_exp;
  }
  ;

EqExp
  : RelExp {
    auto eq_exp = new EqExpAST();
    eq_exp -> rel_exp = unique_ptr<BaseAST>($1);
    eq_exp -> mode = 1;
    $$ = eq_exp;
  }
  | EqExp EQ RelExp {
    auto eq_exp = new EqExpAST();
    eq_exp -> eq_exp = unique_ptr<BaseAST>($1);
    eq_exp -> mode = 2;
    eq_exp -> op = "==";
    eq_exp -> rel_exp = unique_ptr<BaseAST>($3);
    $$ = eq_exp;
  }
  | EqExp NE RelExp {
    auto eq_exp = new EqExpAST();
    eq_exp -> eq_exp = unique_ptr<BaseAST>($1);
    eq_exp -> mode = 2;
    eq_exp -> op = "!=";
    eq_exp -> rel_exp = unique_ptr<BaseAST>($3);
    $$ = eq_exp;
  }
  ;

LAndExp
  : EqExp {
    auto land_exp = new LAndExpAST();
    land_exp -> eq_exp = unique_ptr<BaseAST>($1);
    land_exp -> mode = 1;
    $$ = land_exp;
  }
  | LAndExp AND EqExp {
    auto land_exp = new LAndExpAST();
    land_exp -> land_exp = unique_ptr<BaseAST>($1);
    land_exp -> mode = 2;
    land_exp -> op = "&&";
    land_exp -> eq_exp = unique_ptr<BaseAST>($3);
    $$ = land_exp;
  }
  ;

LOrExp
  : LAndExp {
    auto lor_exp = new LOrExpAST();
    lor_exp -> land_exp = unique_ptr<BaseAST>($1);
    lor_exp -> mode = 1;
    $$ = lor_exp;
  }
  | LOrExp OR LAndExp {
    auto lor_exp = new LOrExpAST();
    lor_exp -> lor_exp = unique_ptr<BaseAST>($1);
    lor_exp -> mode = 2;
    lor_exp -> op = "||";
    lor_exp -> land_exp = unique_ptr<BaseAST>($3);
    $$ = lor_exp;
  }
  ;


ConstExp
  : Exp {
    auto const_exp = new ConstExpAST();
    const_exp -> exp = unique_ptr<BaseAST>($1);
    $$ = const_exp;
  }
  ;
%%

// 定义错误处理函数, 其中第二个参数是错误信息, parser 如果发生错误 (例如输入的程序出现了语法错误), 就会调用这个函数
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  extern char* yytext;  // 声明 yytext
  extern int yylineno;  // 声明 yylineno
  cerr << "error: " << s << endl;
   cerr << "near " << yytext << endl;
   cerr << "line " << yylineno << endl;
}

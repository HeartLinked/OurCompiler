#pragma once

#include <iostream>
#include <memory>
#include <vector>
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
        cerr << "Dump CompUnitAST" << endl;
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
        cerr << "Dump FuncDefAST" << endl;
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

    int Traverse() const override {
        cerr << "Traverse DeclAST" << endl;
        const_decl->Traverse();
        return -1;
    }
};

// ConstDecl := "const" Btype ConstDef {"," ConstDef} ";"
class ConstDeclAST : public BaseAST {
  public:
    // 常量类型
    std::unique_ptr<BaseAST> b_type;
    // 常量定义
    std::unique_ptr<vector<unique_ptr<BaseAST>> > const_defs;

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

    int Traverse() const override {
     /*   cerr << "Traverse ConstDecl" << endl;
        for (auto &const_def : const_defs) {
            const_def->Traverse();
        }
        return -1;*/
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

    int Traverse() const override {
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

    int Traverse() const override {
     /*  cerr << "Traverse ConstDef" << endl;
        cout << "@" << const_name << " = ";
        const_init_val->Traverse();
        cout << endl;
        return -1; */
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

    int Traverse() const override {
      /*  cerr << "Traverse ConstInitValAST" << endl;
        const_exp->Traverse();
        return -1;  */
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

// Block := '{' Stmt '}'
class BlockAST : public BaseAST {
  public:
    // 块内的语句，目前只有一条返回指令
    // std::unique_ptr<BaseAST> block_item;
    std::unique_ptr<vector<unique_ptr<BaseAST>> > block_items;

    void Dump() const override {
        cerr << "Dump BlockAST" << endl;
        std::cout << "BlockAST { ";
        for (auto &item : *block_items) {
            item->Dump();
            std::cout << ", ";
        }
        std::cout << " }";
    }

    int Traverse() const override {
      /* cerr << "Traverse BlockAST" << endl;
        block_item->Traverse();
        return -1; */
    }

    // std::vector<std::unique_ptr<BaseAST>> stmts;
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

    int Traverse() const override {
      /*  cerr << "Traverse BlockItemAST" << endl;
        if (decl) {
            decl->Traverse();
        } else {
            stmt->Traverse();
        }
        return -1; */
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

    int Traverse() const override {
        cerr << "Traverse StmtAST" << endl;
        int x = exp->Traverse();
        cout << "   ret  %" << x << endl;
        cout << endl;
        return -1;
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

    int Traverse() const override {
        cerr << "Traverse ExpAST" << endl;
        int x = lor_exp->Traverse();
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

    int Traverse() const override {
    /*    cerr << "Traverse Lval" << endl;
        cout << "   %" << name;
        return -1;   */
    }
};

// PrimaryExp := '(' Exp ')'
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
        } else if(mode == 3){
            std::cout << " " << number << " ";
        } else {
            lval->Dump();
        }
        std::cout << " }";
    }

    int Traverse() const override {
        cerr << "Traverse PrimaryExpAST " << endl;
        if (mode == 1) {
            int x = exp->Traverse();
            return x;
        } else if(mode == 3){
            int x = gen();
            cout << "   %" << x << " = add 0, " << number << endl;
            return x;
        } else {
          // TODO: lval
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

    int Traverse() const override {
         cerr << "Traverse MulExp" << endl;
          if (mode == 1) {
              int x = unary_exp->Traverse();
              return x;
          } else {
              int x = mul_exp->Traverse(), y = -1, z = unary_exp->Traverse();
              if (op == "*") {
                  y = gen();
                  cout << "   %" << y << " = mul %" << x << ", %" << z << endl;
              } else if (op == "/") {
                  y = gen();
                  cout << "   %" << y << " = div %" << x << ", %" << z << endl;
              } else if (op == "%") {
                  y = gen();
                  cout << "   %" << y << " = rem %" << x << ", %" << z << endl;
              }
              return y;
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

    int Traverse() const override {
         cerr << "Traverse AddExp" << endl;
          if (mode == 1) {
              int x = mul_exp->Traverse();
              return x;
          } else {
              int x = add_exp->Traverse(), y = -1, z = mul_exp->Traverse();
              if (op == "+") {
                  y = gen();
                  cout << "   %" << y << " = add %" << x << ", %" << z << endl;
              } else if (op == "-") {
                  y = gen();
                  cout << "   %" << y << " = sub %" << x << ", %" << z << endl;
              }
              return y;
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

    int Traverse() const override {
      cerr << "Traverse RelExp" << endl;
        if (mode == 1) {
            int x = add_exp->Traverse();
            return x;
        } else {
            int x = rel_exp->Traverse(), y = -1, z = add_exp->Traverse();
            if (op == "<") {
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
            return y;
        }
    }
};

// EqExp := RelExp
// EqExp := EqExp ('==' | '!=') RelExp
class EqExpAST : public BaseAST{
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

      int Traverse() const override {
          cerr << "Traverse EqExp" << endl;
          if (mode == 1) {
              int x = rel_exp->Traverse();
              return x;
          } else {
              int x = eq_exp->Traverse(), y = -1, z = rel_exp->Traverse();
              if (op == "==") {
                  y = gen();
                  cout << "   %" << y << " = eq %" << x << ", %" << z << endl;
              } else if (op == "!=") {
                  y = gen();
                  cout << "   %" << y << " = ne %" << x << ", %" << z << endl;
              }
              return y;
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

      int Traverse() const override {
          cerr << "Traverse LAndExp" << endl;
          if (mode == 1) {
              int x = eq_exp->Traverse();
              return x;
          } else {
              int x = land_exp->Traverse(), y = -1, z = eq_exp->Traverse();
              if (op == "&&") {
                  y = gen();
                  cout << "   %" << y << " = and %" << x << ", %" << z << endl;
              }
              return y;
          }
      }
};

// LOrExp := LAndExp
// LOrExp := LOrExp '||' LAndExp
class LOrExpAST : public BaseAST {
  public :
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

      int Traverse() const override {
          cerr << "Traverse LOrExp" << endl;
          if (mode == 1) {
              int x = land_exp->Traverse();
              return x;
          } else {
              int x = lor_exp->Traverse(), y = -1, z = land_exp->Traverse();
              if (op == "||") {
                  y = gen();
                  cout << "   %" << y << " = or %" << x << ", %" << z << endl;
              }
              return y;
          }
      }
};

// ConstExp := Exp
class ConstExpAST : public BaseAST {
  public :
      std::unique_ptr<BaseAST> exp;

      void Dump() const override {
          cerr << "Dump ConstExp" << endl;
          std::cout << "ConstExp { ";
          exp->Dump();
          std::cout << " }";
      }

      int Traverse() const override {
        /*  cerr << "Traverse ConstExp" << endl;
          int x = exp->Traverse();
          return x;  */
      }
};
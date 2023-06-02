#include "AST.hpp"
#include "CodeGen.hpp"
#include "DsDef.hpp"
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include "AST.hpp"
#include "koopa.h"
#include<fstream>
#include "IRGen.hpp"
#include<string.h>
#include<cstring>
#include "utils.hpp"
#include <unordered_map>
#include <vector>

using namespace std;

// 声明 lexer 的输入, 以及 parser 函数
// 为什么不引用 sysy.tab.hpp 呢? 因为首先里面没有 yyin 的定义
// 其次, 因为这个文件不是我们自己写的, 而是被 Bison 生成出来的
// 你的代码编辑器/IDE 很可能找不到这个文件, 然后会给你报错 (虽然编译不会出错)
// 看起来会很烦人, 于是干脆采用这种看起来 dirty 但实际很有效的手段
extern FILE *yyin;
extern int yyparse(unique_ptr<BaseAST> &ast);
extern void ParseAST(unique_ptr<BaseAST> &ast);
SymbolTable symbolTable;
stack<BlockSymbolTable *> symbolTableStack;
stack<string> whileLevelsStack;
vector<string> s1 = {};
paramentsTable paraments = paramentsTable(false, s1, s1);
unordered_map<string, string> m1 = {};
unordered_map<string, string> m2 = {};
mapTable maptable = mapTable(false, m1, m2);
functionTable functiontable = functionTable(false, s1);
unordered_map<string, bool> is_func_void = {};
string func_now = "";

int main(int argc, const char *argv[]) {
    // 解析命令行参数. 测试脚本/评测平台要求你的编译器能接收如下参数:
    // compiler 模式 输入文件 -o 输出文件
    assert(argc == 5);
    auto mode = argv[1];//mode=-ir -riscv
    auto input = argv[2];//.c
    auto output = argv[4];//out file

     // 打开输入文件, 并且指定 lexer 在解析的时候读取这个文件
    yyin = fopen(input, "r");
    assert(yyin);

    std::cout.setf(std::ios::unitbuf);
    std::cerr.setf(std::ios::unitbuf);

    freopen(output, "w", stdout);
    // yyin = fopen("hello.c", "r");

    cout << "Start parsing..." << endl;
    unique_ptr<BaseAST> ast;
    auto ret = yyparse(ast);
    assert(!ret);
    cout << "Parse success!" << endl;
    ast->Dump();
    cout << endl << endl;
    
    cout<<"decl @getint(): i32"<<endl
        <<"decl @getch(): i32"<<endl
        <<"decl @getarray(*i32): i32"<<endl
        <<"decl @putint(i32)"<<endl
        <<"decl @putch(i32)"<<endl
        <<"decl @putarray(i32, *i32)"<<endl
        <<"decl @starttime()"<<endl
        <<"decl @stoptime()"<<endl;

    ParseAST(ast);
    cout << endl;

    // symbolTable.output();

    if(strcmp(mode,"-ir")==0){
        std::time_t currentTime = std::time(nullptr);
        // 将时间格式化为字符串
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
                    std::localtime(&currentTime));
        // 输出格式化后的时间字符串
        std::cout << "当前时间：" << buffer << std::endl;
        fclose(stdout);
        return 0;
    }
    fclose(stdout);
    char buf[1024] = {0};
    // TransferIR(buf, "testForIR.out");
    // freopen("IRtest.out", "w", stdout);
    TransferIR(buf, output);
    freopen(output, "w", stdout);
    IRGenerate(buf);
    return 0;
}

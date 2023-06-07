#pragma once

#include "AST.hpp"
#include "koopa.h"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <fstream>
#include <string.h>
#include <cstring>

class RiscvGen
{
private:
    string riscv_str; //输出的riscv文本内容

public:
    bool if_immediate(int i)
    {
        return i >= -2048 && i <= 2047;
    }

    //添加字符串作为输出
    void append(const string &str)
    {
        riscv_str += str;
    }

    //label标记
    void label(const string &name){
        this->append(name + ":\n");
    }

    //sp
    void sp(int delta)
    {
        if(this->if_immediate(delta))
            this->binary("addi", "sp", "sp", to_string(delta));
        else
        {
            this->li("t0", delta);
            this->binary("add", "sp", "sp", "t0");
        }
    }

    //ret
    void ret()
    {
        riscv_str += "  ret\n";
    }

    //li
    void li(const string &to, int im)
    {
        riscv_str += "  li    " + to + ", " + to_string(im) + "\n";
    }

    //binary
    void binary(const string &op, const string &rd, const string &rs1, const string &rs2)
    {
        riscv_str += "  " + op + string(6 - op.length(), ' ') + rd + ", " + rs1 + ", " + rs2 + "\n";
    }

    //two
    void two(const string &op, const string &a, const string &b)
    {
        riscv_str += "  " + op + string(6 - op.length(), ' ') + a + ", " + b + "\n";
    }

    //store
    void store(const string &from, const string &base ,int offset)
    {
        if(this->if_immediate(offset))
            riscv_str += "  sw    " + from + ", " + to_string(offset) + "(" + base + ")\n";    
        else
        {
            this->li("t3", offset);
            this->binary("add", "t3", "t3", base);
            riscv_str += "  sw    " + from + ", " + "0" + "(" + "t3" + ")\n";  
        }
    }

    //load
    void load(const string &to, const string &base ,int offset)
    {
        if(this->if_immediate(offset))
            riscv_str += "  lw    " + to + ", " + to_string(offset) + "(" + base + ")\n";    
        else
        {
            this->li("t3", offset);
            this->binary("add", "t3", "t3", base);
            riscv_str += "  lw    " + to + ", " + "0" + "(" + "t3" + ")\n";    
        }
    }

    //la
    void la(const string &to, const string &name)
    {
        this->append("  la    " + to + ", " + name + "\n");
    }
    
    void jump(const std::string &target){
        this->append("  j     " + target + "\n");
    }

    void bnez(const std::string &rs, const std::string &target){
        this->two("bnez", rs, target);
    }

    void call(const std::string &func){
        this->append("  call " + func + "\n");
    }

    void word(int i){
        this->append("  .word " + std::to_string(i) + "\n");
    }

    void zeroInitInt(){
        this->append("  .zero 4\n");
    }

    void br(const std::string &v, const std::string &then_s, const std::string &else_s){
        this->append("  br " + v + ", " + then_s + ", " + else_s + '\n');
    }
    
    //output
    const char* c_str()
    {
        return riscv_str.c_str();
    }
};

class TempLabel{
    private:
        int count=0;
    public:
        std::string StickTable(){
            return "LABEL"+std::to_string(count++);
        }
};
#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

// 遍历 AST 的返回值的数据结构
struct Data {

    // mode = 1 表示返回的value是常量的数值
    // mode = 2 表示返回的是变量本身，其中的变量名在 name
    // 中，使用时需在前面加上@ mode = 3 表示返回的是含变量的表达式，其内容在
    // symbol 中，使用时需在前面加上% mode = 0 表示返回的不是表达式类型
    Data(int mode, int value, string name, string symbol)
        : mode(mode), value(value), name(name), symbol(symbol) {}

    int mode;
    int value;
    string name;
    string symbol;
};


class SymbolTable {
  public:
    // 插入新符号，如果符号已经存在，返回 false，否则返回 true
    bool insertConstSymbol(const std::string &name, std::string value) {
        // 如果符号已经存在，返回 false
        if (table.find(name) != table.end() ||
            table_variable.find(name) != table_variable.end()) {
            return false;
        }
        // 插入新符号
        table[name] = value;
        return true;
    }

    // 插入新符号，如果符号已经存在，返回 false，否则返回 true
    bool insertVirableSymbol(const std::string &name, std::string value) {
        // 如果符号已经存在，返回 false
        if (table_variable.find(name) != table_variable.end() ||
            table.find(name) != table.end()) {
            return false;
        }
        // 插入新符号
        table_variable[name] = value;
        return true;
    }

    void changeValue(const std::string &name, std::string value) {
        if (table_variable.find(name) != table_variable.end()) {
            table_variable[name] = value;
        } else {
            table[name] = value;
        }
    }

    bool isConst(const std::string &name) const {
        auto iter = table.find(name);
        if (iter == table.end()) {
            return false;
        }
        return true;
    }

    bool isVirable(const std::string &name) const {
        auto iter = table_variable.find(name);
        if (iter == table_variable.end()) {
            return false;
        }
        return true;
    }

    int getConstValue(const std::string &name) const {
        auto iter = table.find(name);
        string s = iter->second;
        return stoi(s);
    }

    int getVirableValue(const std::string &name) const {
        auto iter = table_variable.find(name);
        string s = iter->second;
        return stoi(s);
    }

    void output() {
        cout << "const table:" << endl;
        for (auto iter = table.begin(); iter != table.end(); iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << "--------------------------" << endl;
        cout << "variable table:" << endl;
        for (auto iter = table_variable.begin(); iter != table_variable.end();
             iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;
    }

  private:
    std::unordered_map<std::string, std::string> table;
    std::unordered_map<std::string, std::string> table_variable;
};

// 所有 AST 的基类
class BaseAST {
  public:
    virtual ~BaseAST() = default;

    virtual void Dump() const = 0;

    virtual Data Traverse() const = 0;
};

struct BlockSymbolTable{
    SymbolTable table;
    BlockSymbolTable* father;

    bool isConst(const std::string &name) const {
        if(table.isConst(name)) return true;
        BlockSymbolTable* f = this->father;
        while(f != nullptr){
            if(f->table.isConst(name)) return true;
            else f = f->father;
        }
        return false;
    }

    bool isVirable(const std::string &name) const {
        if(table.isVirable(name)) return true;
        BlockSymbolTable* f = this->father;
        while(f != nullptr){
            if(f->table.isVirable(name)) return true;
            else f = f->father;
        }
        return false;
    }

    bool insertConstSymbol(const std::string &name, std::string value) {
        if(isConst(name) || isVirable(name)) return false;
        table.insertConstSymbol(name, value);
        return true;
    }

    bool insertVirableSymbol(const std::string &name, std::string value) {
        if(isConst(name) || isVirable(name)) return false;
        table.insertVirableSymbol(name, value);
        return true;
    }

    bool changeValue(const std::string &name, std::string value) {
        if(table.isVirable(name) || table.isConst(name)){
            table.changeValue(name, value);
            return true;
        } else {
            BlockSymbolTable* f = this->father;
            while(f != nullptr){
                if(f->table.isVirable(name) || f->table.isConst(name)){
                    f->table.changeValue(name, value);
                    return true;
                } else f = f->father;
            }
        }
    }

    int getConstValue(const std::string &name) const {
        if(table.isConst(name)) return table.getConstValue(name);
        BlockSymbolTable* f = this->father;
        while(f != nullptr){
            if(f->table.isConst(name)) return f->table.getConstValue(name);
            else f = f->father;
        }
        return 0;
    }

    int getVirableValue(const std::string &name) const {
        if(table.isVirable(name)) return table.getVirableValue(name);
        BlockSymbolTable* f = this->father;
        while(f != nullptr){
            if(f->table.isVirable(name)) return f->table.getVirableValue(name);
            else f = f->father;
        }
        return 0;
    }
};
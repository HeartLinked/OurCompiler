#pragma once

#include "AST.hpp"
#include "koopa.h"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <fstream>
#include <string.h>
#include <cstring>

void TransferIR(char * buf , const char* file_name);
void IRGenerate(const char* str);
void AllocateLocalAddress(const koopa_raw_function_t &func);
size_t getTypeSize(koopa_raw_type_t ty);
void Visit(const koopa_raw_program_t &program);
void Visit(const koopa_raw_slice_t &slice);
void Visit(const koopa_raw_function_t &func);
void Visit(const koopa_raw_basic_block_t &bb);
void Visit(const koopa_raw_value_t &value);
void Visit(const koopa_raw_return_t &ret);
int Visit(const koopa_raw_integer_t &integer);
void Visit(const koopa_raw_binary_t &binary);
void Visit(const koopa_raw_load_t &load);
void Visit(const koopa_raw_store_t &store);
void Visit(const koopa_raw_jump_t &jump);
void Visit(const koopa_raw_branch_t &branch);
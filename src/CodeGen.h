#pragma once

#include "AST.h"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>


void ParseAST(std::unique_ptr<BaseAST> &ast);


#pragma once

#include "AST.hpp"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"
#include <unordered_map>

void ParseAST(std::unique_ptr<BaseAST> &ast);

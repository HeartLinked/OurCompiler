#pragma once

#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include "AST.h"


void ParseAST(unique_ptr<BaseAST> &ast);
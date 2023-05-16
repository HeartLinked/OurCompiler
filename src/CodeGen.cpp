#include "CodeGen.h"
#include <memory>
#include <unordered_map>
#include <string>

using namespace std;

void ParseAST(unique_ptr<BaseAST> &ast){
    ast -> Traverse();
}


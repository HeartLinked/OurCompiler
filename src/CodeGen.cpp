#include "CodeGen.h"
#include <memory>

using namespace std;

void ParseAST(unique_ptr<BaseAST> &ast){
    
    ast -> Traverse();

}
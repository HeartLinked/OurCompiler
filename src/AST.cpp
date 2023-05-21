#include "AST.hpp"

int cnt = 0, cnt2 = 'A', cnt3 = 'A', cnt4 = 'A';

int gen() { return cnt++; }

char gen2() {return cnt2++;}

char ifGen3() {return cnt3++;}

char elseGen4() {return cnt4++;}
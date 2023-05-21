#include "AST.hpp"

int cnt = 0, cnt2 = 'A', cnt3 = 'A', cnt4 = 'A', cnt5 = 'a';

int gen() { return cnt++; }

char gen2() {return cnt2++;}

char ifGen3() {return cnt3++;}

char whileGen4() {return cnt4++;}

char breakGen5() {return cnt5++;}
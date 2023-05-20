int main() {
  int a = 2;
  if(a) {
    a = a + 1;
  } 
  if(a - 1) {
    if(a - 2 == 1) {
      return a;
    } else {
      a = a + 1;
    }
  }
  //else a = 0;
  return a;
}

int main() {
  int a = 1;
  {
    int b;
    b = 1;
    a = 2;
    b = 4;
    a = 3;
  }
  return a;
}

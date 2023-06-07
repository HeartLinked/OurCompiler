
int main()
{
      int num = 0;
      num=getint();
      int half=num/2;
      int num_j = half * 2;
      if(num != num_j)
      {
        //   putint(1);
          putch(73);
          putch(115);
          putch(32);
          putch(111);
          putch(100);
          putch(100);
          putch(10);
      }
      else
      {
        //   putint(0);
          putch(73);
          putch(115);
          putch(32);
          putch(101);
          putch(118);
          putch(101);
          putch(110);
          putch(10);
      }
      return 0; 
}
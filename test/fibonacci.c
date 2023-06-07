int fib(int m)
{
	if(m==1 || m==2)
	{
		return 1;
	}
	else if(m==0)
    {
        return 0;
    }
    else{
        return fib(m-1)+fib(m-2);
    } 
}
int main()
{
	int n;
	n=getint();
    int res=fib(n);
    putint(res);
    putch(10);
    return 0;
 }
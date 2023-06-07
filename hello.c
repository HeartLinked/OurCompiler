int main()
{
    int a1 = 5;
    int a2 = 3;
    int a3 = 8;

    int n = 3;
    int swapped = 1;

    while (swapped == 1)
    {
        swapped = 0;
        int i = 1;
        while (i < n)
        {
            if (i == 1)
            {
                if (a1 > a2)
                {
                    int temp1 = a1;
                    a1 = a2;
                    a2 = temp1;
                    swapped = 1;
                }
            }
            else if (i == 2)
            {
                if (a2 > a3)
                {
                    int temp2 = a2;
                    a2 = a3;
                    a3 = temp2;
                    swapped = 1;
                }
            }
            i = i + 1;
        }
        n = n - 1;
    }

    putint(a1);
    putch(32);
    putint(a2);
    putch(32);
    putint(a3);
    putch(32);

    return 0;
}

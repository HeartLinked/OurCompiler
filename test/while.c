int main() {
    int a1 = 5;
    int a2 = 3;
    int a3 = 8;
    int a4 = 2;
    int a5 = 1;
    int a6 = 7;
    int a7 = 6;
    int a8 = 10;
    int a9 = 9;
    int a10 = 4;

    int n = 10;
    int swapped = 1;

    while (swapped==1) {
        swapped = 0;
        int i = 1;
        while (i < n) {
            if (i == 1 && a1 > a2) {
                int temp1 = a1;
                a1 = a2;
                a2 = temp1;
                swapped = 1;
            } else if (i == 2 && a2 > a3) {
                int temp2 = a2;
                a2 = a3;
                a3 = temp2;
                swapped = 1;
            } else if (i == 3 && a3 > a4) {
                int temp3 = a3;
                a3 = a4;
                a4 = temp3;
                swapped = 1;
            } else if (i == 4 && a4 > a5) {
                int temp4 = a4;
                a4 = a5;
                a5 = temp4;
                swapped = 1;
            } else if (i == 5 && a5 > a6) {
                int temp5 = a5;
                a5 = a6;
                a6 = temp5;
                swapped = 1;
            } else if (i == 6 && a6 > a7) {
                int temp6 = a6;
                a6 = a7;
                a7 = temp6;
                swapped = 1;
            } else if (i == 7 && a7 > a8) {
                int temp7 = a7;
                a7 = a8;
                a8 = temp7;
                swapped = 1;
            } else if (i == 8 && a8 > a9) {
                int temp8 = a8;
                a8 = a9;
                a9 = temp8;
                swapped = 1;
            } else if (i == 9 && a9 > a10) {
                int temp9 = a9;
                a9 = a10;
                a10 = temp9;
                swapped = 1;
            }
            i=i+1;
        }
        n=n-1;
    }

    // // 打印排序后的结果
    // printf("排序结果：%d %d %d %d %d %d %d %d %d %d\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    putint(a1);
    putch(32);
    putint(a2);
    putch(32);
    putint(a3);
    putch(32);
    putint(a4);
    putch(32);
    putint(a5);
    putch(32);
    putint(a6);
    putch(32);
    putint(a7);
    putch(32);
    putint(a8);
    putch(32);
    putint(a9);
    putch(32);
    putint(a10);
    putch(10);
    return 0;
}
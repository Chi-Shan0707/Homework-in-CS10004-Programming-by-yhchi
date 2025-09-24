//计算机的进制主要包括：二进制（binary）、八进制（octal）、十进制（decimal）和十六进制（hexadecimal）。
#include<stdio.h>
int main()
{
    int x=168;
    int y=0b11;
//    printf(" 十进制 %d 对应的二进制数是:%b\n",x,x);
// query:为什么没有%b输出a
    printf(" 十进制 %d 对应的八进制数是:%o\n",x,x);
    printf(" 十进制 %d 对应的十六进制数是:%x\n",x,x);

    return 0;
}
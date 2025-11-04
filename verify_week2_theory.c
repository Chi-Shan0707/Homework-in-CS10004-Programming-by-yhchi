#include<stdio.h>
int a,b,c;
int d;
int main()
{
    printf("Vefrify the result of Problem 12 on Page 40.\n");
    a=4;
    b=a*a++;
    printf("a=%d,b=%d\n",a,b);
    c=++a+a;
    printf("a=%d,c=%d\n",a,c);
    d=0B10;
    printf("d=%d\n",d);
    return 0;
}
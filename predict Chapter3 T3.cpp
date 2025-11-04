#include<stdio.h>
void func1(int x=5,int y=110)
{
    printf("func1\n");
    while(x<=y)x<<=1;
    printf("x=%d,y=%d",x,y);
    printf("\n*****\n");
}
void func2(int x=5,int y=110)
{
    printf("\nfunc2\n");
    do
    {
        x=y/x;
        y=y-x;
        printf("-> x=%d,y=%d\n",x,y);
    } while (y>=1);
    printf("\nresult:");
    printf("\n%d,%d",x,y);
}
int main()
{
    func1();
    func2();
/*

func1
x=5,y=110
...
x=80,y=110 ok
x=160,y=110 结束循环
result:x=160,y=110
*****

func2
-> x=22,y=88
-> x=4,y=84
-> x=21,y=63
-> x=3,y=60
-> x=20,y=40
-> x=2,y=38
-> x=19,y=19
-> x=1,y=18
-> x=18,y=0 结束循环
result:x=18,y=0





*/
    return 0;
}
#include<stdio.h>
int m,n,p,x,y;
int main()
{
    x=8,y=18;
    printf("x=%d\t y=%d\n",x,y);
    m=(x++)+(++y);
    printf("x=%d\t y=%d\t m=%d\n",x,y,m);
    n=(y--)-(--x);
    printf("x=%d\t y=%d\t n=%d\n",x,y,n);
    p=y%x;
    printf("x=%d\t y=%d\t p=%d\n",x,y,p);
    x=3;
    x+=x/=x-=x*x;
    //从右往左，先x -= x * x  再x /=  最后x+=
    printf("x=%d\n",x);
    return 0;
}
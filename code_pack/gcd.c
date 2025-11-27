#include<stdio.h>
int GCD(int a,int b)
{
    printf("GCD called with a=%d, b=%d\n", a, b);
    if(!a||!b)return a+b;
    return GCD(b,a%b);
/*
if(a<b)等价于swap(a,b)
if(a>b)等价于将a减去尽可能多的b,继续递归
*/
}
int main()
{
    int gcd(int a,int b);
    int m,n;
    scanf(" %d %d",&m,&n);//m,n前可输入任意数量的空格
    printf("gcd of %d and %d is %d\n",m,n,gcd(m,n));
    printf("GCD of %d and %d is %d\n",m,n,GCD(m,n));
    return 0;
}
int gcd(int a,int b)
{
    printf("gcd called with a=%d, b=%d\n", a, b);
    if(!a||!b)return a+b;
    return (a>b)?gcd(a-b,b):gcd(a,b-a);
}
#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    if(n<0||m<0)printf("请输入2个自然数\n");
    if(n<m)printf("%d小于%d\n",n,m);
    if(n>m)printf("%d大于%d\n",n,m);
    if(n==m)printf("%d等于%d\n",n,m);
    if(n!=m)printf("%d不等于%d\n",n,m);
    if(m!=0&&n%m==0)printf("%d被%d整除\n",n,m);
    if(n!=0&&m%n==0)printf("%d被%d整除\n",m,n);
    return 0;
}
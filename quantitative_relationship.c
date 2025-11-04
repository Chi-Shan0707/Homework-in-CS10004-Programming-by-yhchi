#include<stdio.h>
int n,m;int main()
{
    n=m=-1; scanf("%d %d",&n,&m);
/*
匹配失败：%d 转换说明符要求输入的是十进制数字。
当 scanf 在输入流中遇到非数字字符（如字母 'a'）时，它会立即停止读取，并认为这次转换失败了。
故变量 a 未被赋值  -> 变量 a 将保持它原来的值。
*/
    if(n<0||m<0){printf("请重新输入2个自然数\n");return 0;}
    if(n<m)printf("%d小于%d\n",n,m);
    if(n>m)printf("%d大于%d\n",n,m);
    if(n==m)
    {
        printf("%d等于%d\n",n,m);
        if(n!=0)printf("%d与%d互相整除",m,m);
        return 0;
    }
    if(n!=m)printf("%d不等于%d\n",n,m);
    if(m!=0&&n%m==0)printf("%d被%d整除\n",n,m);
    if(n!=0&&m%n==0)printf("%d被%d整除\n",m,n);
//会先进行零判断——若为0，则跳过&&后的语句，不会报错
    return 0;
}
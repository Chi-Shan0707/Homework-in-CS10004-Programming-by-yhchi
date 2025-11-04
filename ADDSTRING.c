#include<stdio.h>
#include<string.h>
#define N 120
int main()
{
    int i,j;
    char s1[N<<1],s2[N];
    printf("请输入第一个字符串：");
    scanf("%s",s1);
    printf("请输入第二个字符串：");
    scanf("%s",s2);
    strcat(s1,s2);
    printf("连接后的字符串为：%s\n",s1);
    return 0;
}
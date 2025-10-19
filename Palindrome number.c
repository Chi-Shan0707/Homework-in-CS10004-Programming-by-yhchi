#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1000];
    int n;
    printf("Tell me the number:");
    scanf("%99s",ch);
    n=strlen(ch); //使用strlen获取字符串的实际长度
    for(int i=0,j=n-1;i<j;++i,--j)
    {
        if(ch[i]<'0'||ch[i]>'9')
        {
            printf("It is not a number.");
            return 0;
        }
        if(ch[i]!=ch[j])
        {
            printf("It is not a palindrome number.");
            return 0;
        }
    }
    printf("It is a palindrome number.");
    return 0;
}
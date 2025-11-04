#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    char s[1001];
    char res[1001]="";
    //char res[1001]={0};
    //char res[1001]={0};也可以这样初始化
    scanf(" %s",s);
    n=strlen(s);//长度不包括'\0'！
//    printf("%d",n);
    i=j=0;
    for(;i<n;)
    {
        res[j]=s[i];
        while(s[i]==res[j])++i;
        ++j;
    }
    printf("%s",res);
    return 0;
}
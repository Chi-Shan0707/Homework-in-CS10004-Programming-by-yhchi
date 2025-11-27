#include<stdio.h>
#include<string.h>
int main()
{
    char s[100] = "";   // s[0]=='\0'，其余元素被初始化为0
    scanf("%s",s);
    char* read;
    char* write;
    read=write=s;
    while(*read!='\0')
    {
        *write=*read;
        while(*read==*write&&*read!='\0')++read;
        ++write;
    }
    *write='\0';
    printf("%s\n",s);
    /*
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
    */
    return 0;
}

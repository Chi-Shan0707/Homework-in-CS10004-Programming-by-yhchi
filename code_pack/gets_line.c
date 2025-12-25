#include<stdio.h>
#include<string.h>
int main()
{
    char str[1004];
    int lc,uc;//lowercase and uppercase count
    gets(str);
    lc=uc=0;
    for(int i=0;i<strlen(str);++i)
    {
        if(str[i]>='a'&&str[i]<='z')++lc;
        if(str[i]>='A' && str[i]<='Z') ++uc;
    }
//   printf("%s", str);
    printf("lowercase: %d\nuppercase: %d",lc, uc);
    return 0;
}
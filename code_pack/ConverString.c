#include<stdio.h>
#include<string.h>
char s[1002]={0};
void upper()
{
    for(int i=0;i<strlen(s);++i)
    {
        if(s[i]>='a'&&s[i]<='z') s[i]-=32;
    }
}
int main()
{
    
 //   char t[1002]={0};
    fgets(s,sizeof(s),stdin);
    upper();
    printf("%s",s);
    return 0;
}
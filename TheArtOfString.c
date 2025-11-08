#include<stdio.h>
#include<string.h>
int n;
char s1[1003],s2[1003]="";
void update()
{
    int len1=strlen(s1);int len2=strlen(s2);
    for(int i=0;i<n;++i)
    {
        for(int j=len2-1+i;j>=i;--j)s2[j+1]=s2[j];
    }
    for(int i=0;i<n;++i)s2[i]=s1[i];
//我的s2数组初始情况下全赋为'\0',所以目前s2最后还有'\0'可以直接输出
}
int main()
{
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    scanf(" %d",&n);
    update();
    puts(s2);
    return 0;
}
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
    for(i=0;s1[i]!='\0';++i);
  //  printf("%d\n",i);
    for(j=0;s2[j]!='\0';++j)
    {
           
        s1[i++]=s2[j];
    }
    s1[i]='\0'; 
    printf("结果为：%s",s1);
    return 0;
}
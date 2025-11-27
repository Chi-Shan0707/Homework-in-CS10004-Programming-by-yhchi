#include<stdio.h>
#include<string.h>
#define N 123
void print(char *str)
{
    char *ptr=str;
    while(*ptr!='\0')
    {
        putchar(*ptr);
        /*int putchar(int c); // 把字符 c（作为 unsigned char 转换后）写到 stdout，等价于 fputc(c, stdout)*/
        ++ptr;
    }
    putchar('\n');
}
void deDuplication(char *str);
int main()
{
    char s[N];
    printf("请输入一个字符串:\n");
    fgets(s,sizeof(s),stdin);
    deDuplication(s);
    print(s);
    printf("去重后的字符串是:\n");
    print(s);
    return 0;
}
void deDuplication(char *str)
{
    char *p1=str;
    char *p2=str;
    for(;*p1!='\0';)
    {
        *p1=*p2;
 //       printf("当前检查字符:%c\n",*p1);
        while(*p2==*p1&&*p2!='\0')++p2;
        ++p1;
    }
    *p1='\0';
}
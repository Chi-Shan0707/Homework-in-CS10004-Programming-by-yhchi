#include<stdio.h>
#include<string.h>
#define N 120
void print(char *str)
{
    char *ptr=str;
    while(*ptr!='\0')
    {
        putchar(*ptr);
        ++ptr;
    }
    putchar('\n');
}
//宏是预处理指令,在编译前进行简单的文本替换，所以N不具有类型
void myStrCat(char str1[],char str2[],int *length)
{
    int len=0;
    char *p1=str1;
    char *p2=str2;
    while(*p1!='\0')++p1,++len;
    for(;*p2!='\0';++p2)
    {
        *p1=*p2;
        ++p1;//这是指针移动到下一个元素位置，和char一个字节无关
        //即便是int数组的指针也是++
        ++len;
    }
    *p1='\0';
    *length=len;
    return;
}
int main()
{
    char s1[N<<1],s2[N];int LENGTH;
 //   char *p1=s1,*p2=s2;
    printf("请输入第一个字符串:\n");
//    fgets(s1,sizeof(s1),stdin);
    scanf(" %s",s1);
    printf("请输入第二个字符串:\n");
    scanf(" %s",s2);
//    fgets(s2,sizeof(s2),stdin);
    //教材上神奇的操作
//    for(p1=s1;*p1!='\0';++p1);
 //   for(p2=s2;*p1++=*p2++;);
//suggest parentheses around assignment used as truth value [-Wparentheses]
    /*
    我已经修复了代码中的警告：在 for 循环条件中给赋值表达式加上了括号（(*p1++=*p2++)），这样编译器就不会再发出 -Wparentheses 警告。

为什么会出现这个警告
GCC 的 -Wparentheses 选项会警告在条件语句中使用赋值运算符（=）作为真值（truth value），因为这通常是编程错误（可能想写 == 比较）。
在你的代码中，for(p2=s2;*p1++=*p2++;); 的条件是 *p1++=*p2++，这是一个赋值表达式（复制字符），其结果是 *p2 的值（当 *p2 为 '\0' 时，结果为 0，循环结束）。这是正确的字符串连接逻辑，但编译器建议用括号明确意图。
修复后的代码
    */
    print(s1);
    print(s2);
    myStrCat(s1,s2,&LENGTH);
    printf("连接后的字符串长度是: %d\n",LENGTH);
    printf("连接后的字符串是:\n");
    print(s1);
    return 0;
}
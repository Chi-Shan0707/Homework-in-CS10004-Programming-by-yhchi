
/*
题意不详，只能猜测：
char s[]="ABCXABCZABC";  要求在主函数内输出字符串“BXBZB”
意思是删除所有A和C字符
*/

#include <stdio.h>
void squeeze(char *s, const char *t)
//好的指针写法嘿嘿
{
    char *read=s;
    char *write=s;
    //分拆为读和写两步
    const char *search;
    int flag;

    while(*read != '\0') {
        flag=0;
        for(search=t;*search!='\0';++search)
        {
            if (*read==*search)
            {
                flag=1; 
                break; 
            }
        }
        if(!flag)
        {
            *write = *read;
            write++;
        }
        ++read;
    }
    *write = '\0';
    //莫忘！
}

int main() {
    // 定义测试样例
    char input[100];
    char STD[]="AC";
    scanf("%s",input);
    // 调用函数，删除 'A' 和 'C'
    squeeze(input,STD);
    
    printf("处理后结果: %s\n", input);

    return 0;
}
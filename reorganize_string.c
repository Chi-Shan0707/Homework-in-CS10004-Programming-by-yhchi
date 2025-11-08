#include<stdio.h>
#include<string.h>
#define N 1002
char str[N];
int i,j;
char output[N];
void operate()
{
    for(i=0,j=0;i<strlen(str);++i)
    {
        if(str[i]!=' '&&str[i]!='\n'&&str[i]!='\t'&&str[i]!='\0'&&str[i]!='\r')
        {
            output[j++]=str[i];
        }
        else 
        {
            int flag=0;
            while(str[i+1]==' '||str[i+1]=='\n'||str[i+1]=='\t'||str[i+1]=='\0'||str[i+1]=='\r')
            {
                ++i;
               flag=1;
            }
            if(flag==1) output[j++]=str[i];
        }
    }
}
int main()
{
    
    fgets(str,sizeof(str),stdin);
    operate();
    output[j]='\0';//标记字符串结束：
    /*
确保正确输出：当你使用 printf("%s", output); 输出字符串时，printf 函数会从数组开始位置一直输出到遇到 '\0' 为止。如果没有这个结束符，printf 会继续输出数组后面的内存内容，直到偶然遇到一个0字节为止，这会产生乱码或不可预知的结果。
*/

    printf("%s",output);
    return 0;
}

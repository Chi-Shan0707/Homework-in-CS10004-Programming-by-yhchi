#include<stdio.h>
int main()
{
    char ch;
    int cnt[4]={0};
    printf("输入字符问号中止");
    while(ch=getchar())
    {
        if(ch=='?')
        {
            break;
        }
        if(ch!='\n'||ch!='\r')
//疑问 这里换行是\r 还是\n
//\r是回车符，回车符是什么啊啊????
        {
            if(ch>='a'&&ch<='z')cnt[0]++;
            else if(ch>='A'&&ch<='Z') cnt[1]++;
            else if(ch>='0'&&ch<='9')  cnt[2]++;
            else cnt[3]++;
            
        }
    }
    printf("小写字母%d\n大写字母%d\n数字%d\n其他字符%d\n",cnt[0],cnt[1],cnt[2],cnt[3]);
    return 0;
}
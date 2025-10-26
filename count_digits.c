#include<stdio.h>
#include<string.h>
/*
思考：与直接输入整数相比(如先前通过取余方式判断回文数)，使用数组的优势（思考不做作业要求）。

嘶，回文数就已经数组秒掉了
*/
int main()
{
    char s[1025];int len;
    int cnt[10] = {0};
    scanf("%1024s",s);
    len=strlen(s);
    for(int i=0;i<len;++i)
    {
        if(i==0&&s[i]=='-')printf("首先我要指出这是个负数\n");
        else ++cnt[s[i]-'0'];
    }
    for(int i=0;i<10;++i)printf("%d的个数是%d\n",i,cnt[i]);
    return 0;
}
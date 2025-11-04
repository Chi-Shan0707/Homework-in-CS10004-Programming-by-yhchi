#include<stdio.h>
#include<string.h>
/*
思考：与直接输入整数相比(如先前通过取余方式判断回文数)，使用数组的优势（思考不做作业要求）。

嘶，回文数就已经数组秒掉了
*/
int main()
{
    /*
    example:4294967296
通过数组实现题设要求，该整数按位存入一个数组，统计各数字出现的次数也存入一个数组
    */
    char s[1025];int len;
    int cnt[10] = {0};
    scanf("%1024s",s);
    len=strlen(s);//完成第一个要求：按位存入数组
    for(int i=0;i<len;++i)
    {
        if(i==0&&s[i]=='-')printf("首先我要指出这是个负数\n");
        else ++cnt[s[i]-'0'];
        //完成第二个要求：在数组中统计各数字出现的次数
    }
    for(int i=0;i<10;++i)printf("%d的个数是%d\n",i,cnt[i]);
    return 0;
}
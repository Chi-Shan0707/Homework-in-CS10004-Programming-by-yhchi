#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define BASE 53
#define MOD1 1013
#define MOD2 101
/*
数组的大小必须是“整数常量表达式”（integer constant expression），而 const int n = 10; 是一个对象定义，不被视作整数常量表达式，所以不能用作全局数组大小；编译器因此把它当成可变长度（VLA），但 VLA 不能出现在文件作用域，导致“variably modified … at file scope”错误。
*/
char *words[MOD1][MOD2];
int cnt[MOD1][MOD2];

void insert(char *str)
{
    long encode1=0;
    long encode2=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            encode1=encode1*BASE+str[i]-'a'+26;
            encode2=encode2*BASE+str[i]-'a'+26;
            encode1%=MOD1;
            encode2%=MOD2;
        }
        else
        {
            encode1=encode1*BASE+str[i]-'A';
            encode2=encode2*BASE+str[i]-'A';
            encode1%=MOD1;
            encode2%=MOD2;
        }
    }
  
   words[encode1][encode2] = str; 
    //相信自己不会撞
   
    ++cnt[encode1][encode2];
  //    printf("test: %ld %ld %s \n",encode1,encode2,words[encode1][encode2]);
}
int main()
{
    int i,j,MX;int n=0;
    MX=0;
    char filename[1000];char INPUT[100][100];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *fp=fopen(filename,"r");
    /*
    fscanf 的返回值主要有以下几种（假设没有其他错误）：

1. 正整数：表示成功读取的项数。

对于 fscanf(fp, " %s", word)，如果成功读取了一个字符串（单词），返回值是 1。
如果格式字符串中有多个 %s 或其他转换符，返回值会是实际读取的项数（例如，fscanf(fp, "%s %d", str, &num) 如果都成功，返回 2）。
2. 0：表示没有成功读取任何项，但文件没有结束。

这通常发生在格式不匹配时（例如，期望数字但遇到非数字字符）。对于 %s，这种情况很少见，因为 %s 会跳过空白并读取下一个单词，除非文件为空或格式完全不匹配。

3. EOF（通常是 -1）：表示文件结束（EOF）或发生读取错误。

当到达文件末尾时，返回 EOF。
如果文件指针无效或发生 I/O 错误，也返回 EOF。
对于你的代码的具体分析
    */
    if(!fp)
    {
        printf("404 NOT FOUND\n");
        return 1;
    }
    memset(words, 0, sizeof(words));
    memset(cnt, 0, sizeof(cnt));
    while(fscanf(fp, " %s", INPUT[n])==1)
    {
        insert(INPUT[n]);
        ++n;
    }
    fclose(fp);
    /*
    `fclose(fp);` 用于关闭文件流，刷新缓冲区确保数据写入磁盘，并释放系统资源（如文件描述符）。  
不关闭可能导致数据丢失或资源泄漏。  
最佳实践：文件操作后及时调用。
    */
   
    for(i=0;i<MOD1;i++)
    {
        for(j=0;j<MOD2;j++)
        {
            MX=(cnt[i][j]>MX?cnt[i][j]:MX);
//        if(cnt[i][j])    printf("test: %d %d %s--%d\n",i, j, words[i][j],cnt[i][j]);
        }
    }
    for(i=0;i<MOD1;i++)
    {
        for(j=0;j<MOD2;j++)
        {
            if(cnt[i][j]==MX)
            {
                printf("%s--%d\n",words[i][j],MX);
            }
        }
    }
    return 0;
}
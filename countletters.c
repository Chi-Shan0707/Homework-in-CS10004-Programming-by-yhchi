#include<stdio.h>
#include<string.h>
int main()
{
//s[i]-'0's[i]是字符型，运算过程中会先做"整数提升"变成int，所以可以加减运算
//s[i]=s[i]-1还包含"整形下降"(复制过程是下降)
    char s[1025];int len;int cnt[128]={0};
    scanf("%1024s",s);
    len=strlen(s);
    for(int i=0;i<len;++i)++cnt[max(s[i],0)];//防止越界
        
 //       ++cnt[(int)s[i]];
 /*
 这里(int)是不是非常必要，因为这里并没有运算不会有”整型提升“？
 不是的，不需要显式 (int)。
要点（简短）：

在表达式中，s[i]（类型 char）会自动做整数提升（integer promotion）到 int，所以作为数组下标或参与算术时不需要显式转换为 int。++cnt[(int)s[i]]; 与 ++cnt[s[i]]; 在多数情况下等价。
风险在于 char 可能是有符号的（signed），当字符的值为负（例如非 ASCII 字节）时会产生负下标，导致未定义行为。为安全应先转换为 unsigned char 并把计数数组大小设为 256。
建议替换为（更安全、可移植）：
 */
    
    for(int i='A';i<='Z';++i)
    {
        if(cnt[i])printf("%c:%d\n",i,cnt[i]);
    }
    for(int i='a';i<='z';++i)
    {
        if(cnt[i])printf("%c:%d\n",i,cnt[i]);
    }
    return 0;
}
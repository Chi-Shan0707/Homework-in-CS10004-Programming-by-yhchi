#include<stdio.h>
int read()
{
    int res=0,flag=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;}
    while('0'<=ch&&ch<='9')res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
    return res*flag;
}
int MAX(int x,int y){return (x>y)?x:y;}
int MIN(int x,int y){return (x<y)?x:y;}
int main()
{
    int a,b,c;a=read(),b=read(),c=read();
    int sum;    sum=a+b+c;
    printf("和：%d\n",sum);
    float Average;  Average=sum/3.0;//会按照“最大”的，即浮点数去计算
    printf("平均数：%.2f\n",Average);
    printf("最大数：%d\n",MAX(a,MAX(b,c)));
    printf("最小数：%d\n",MIN(a,MIN(b,c)));
    return 0;
}
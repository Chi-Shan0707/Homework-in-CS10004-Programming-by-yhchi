#include<stdio.h>
#define max(a,b) ((a)<(b)?(b):(a))
#define MaxOfThree(a,b,c) max(a,max(b,c))
int main()
{
    int x,y,z;
    printf("请输入3个整数：\n");
    scanf(" %d %d %d",&x,&y,&z);
    printf("3个数中最大的数是：%d\n",MaxOfThree(x,y,z));
    return 0;
}
#include<stdio.h>
int main()
{
    int n,a[102][102]={0};
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int x=1,y=1,dir=0;
    int cur=0;//current

    scanf(" %d",&n);
//在外部建立一圈围墙
//不在意时间复杂度就是了
    for(int i=0;i<=n+1;++i)
    {
        for(int j=0;j<=n+1;++j)
        {
            if(i==0||j==0||i==n+1||j==n+1)a[i][j]=-1;
        }
    }
/*
我们通过指针移动模拟填表的移动过程
*/
//dir=-,1,2,3分别表示向右、向下、向左、向上移动
    for(;;)
    {
        a[x][y]=++cur;
        /*
        状态更新
        重点一：越界处理
        重点二：方向判断
        */
//采用dx,dy精简代码
        if(a[x+dx[dir]][y+dy[dir]]!=0)//遇到边界或已填入数字
        {
            dir=(dir+1)%4;//改变方向
        }
        x+=dx[dir];
        y+=dy[dir];
        if(cur==n*n)break;//填满退出
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
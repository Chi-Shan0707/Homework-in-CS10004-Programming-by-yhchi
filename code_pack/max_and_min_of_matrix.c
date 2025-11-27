#include<stdio.h>
int main()
{
    int a[102][102];
    int n,m;
    int mn[102],MX[102];
    printf("请输入矩阵的阶数\n");
    scanf(" %d %d",&m,&n);
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            scanf(" %d",&a[i][j]);
        }
    }
    for(int i=1;i<=m;++i)
    {
        int mn=a[i][1],mx=a[i][1];
        for(int j=2;j<=n;++j)
        {
            if(a[i][j]<mn)mn=a[i][j];
            if(a[i][j]>mx)mx=a[i][j];
        }
        printf("第%d行最小值为%d,最大值为%d\n",i,mn,mx);
        printf("最小值在第");for(int j=1;j<=n;++j){if(a[i][j]==mn)printf("%d  ",j);}printf("列取得。\n");
        printf("最大值在第");for(int j=1;j<=n;++j){if(a[i][j]==mx)printf("%d  ",j);}printf("列取得。\n");
        printf("**************\n");
    }
    return 0;
}
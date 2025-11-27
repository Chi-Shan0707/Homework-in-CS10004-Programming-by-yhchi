#include<stdio.h>
int n,a[103][103],tempt,dir;
void rotate(int i,int j)
{
    double x,y;
    double center;
    center=(n+1)/2.0;
    x=center-i;
    y=center-j;
    for(int k=1;k<=((dir==1)?3:1);++k)
    {
        tempt=a[i][j];
        a[i][j]=a[(int)(center-y)][(int)(center+x)];
        a[(int)(center-y)][(int)(center+x)]=a[(int)(center+x)][(int)(center+y)];
        a[(int)(center+x)][(int)(center+y)]=a[(int)(center+y)][(int)(center-x)];
        a[(int)(center+y)][(int)(center-x)]=tempt;
    }
}
int main()
{
    scanf(" %d",&n);for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)scanf(" %d",&a[i][j]);} printf("\n输入旋转方向：1-顺时针，-1-逆时针");scanf(" %d",&dir);
    for(int i=1;i<=((n+1)>>1);++i)//层数
    {
        int len=n+1-(i<<1);
        for(int j=i;j<=i+len-1;++j)
        {
            rotate(i,j);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int a[102][102]={0};
    int n,cur=0,dir=1;
    scanf(" %d",&n);
    for(int tot=2;tot<=(n<<1);++tot)//枚举列标
    {
        int i,j;
        switch(dir)
        {
            case 0:
                if(tot<=n+1)
                {
                    i=tot-1,j=1;
                    for(;i>=1&&j<=tot;--i,++j)a[i][j]=++cur;
                }
                else
                {
                    i=n,j=tot-n;
                    for(;j<=n;--i,++j)a[i][j]=++cur;
                }
                break;
            case 1:
                if(tot<=n+1)
                {
                    i=1,j=tot-1;
                    for(;j>=1;++i,--j)a[i][j]=++cur;
                }
                else
                {
                    i=tot-n,j=n;
                    for(;i<=n;++i,--j) a[i][j]=++cur;
                }
        }
        dir^=1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

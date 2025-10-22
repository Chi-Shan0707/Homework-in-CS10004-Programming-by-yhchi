#include<stdio.h>

int main()
{
    int n;int c[104][104];
    printf("Input n= ");
    scanf(" %d",&n);
    for(int i=0;i<=n;++i)c[i][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(i>j)printf("%6c",' ');
            else printf("%6d",c[j][i]);
        }
        printf("\n");
    }
    return 0;
}
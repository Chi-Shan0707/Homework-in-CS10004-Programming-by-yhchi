#include<stdio.h>
int main()
{
    int a[104][104]={0};
    int n;
    scanf(" %d",&n);
    if(n==1){printf("1\n");return 0;}
    a[1][1]=1;
    a[1][2]=3;  
    a[2][1]=2;
    for(int i=1;i<=n;++i)
    {
        for(int j=i-1;j<=i+1;++j)
        {
            if(i+j<=3)continue;
            a[i][j]=a[i-1][j-1]+3;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)printf("%d\t",a[i][j]);
        printf("\n");
    }
    return 0;
}
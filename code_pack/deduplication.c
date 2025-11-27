#include<stdio.h>
int main()
{
    int n;int a[1004];int temp;a[0]=0;
    scanf(" %d",&n);
    for(int i=1;i<=n;++i)scanf(" %d",&a[i]);
    for(int i=1;i<=n;++i)//轮次，每次把最大换到右端
    {
        for(int j=1;j<=n-i;++j)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=1;i<=n;++i)printf("%d ",a[i]);
    printf("\n");
    for(int i=1;i<=n;)
    {
        a[++a[0]]=a[i];
        while(a[i]==a[a[0]])++i;
    }
    n=a[0];//多用了一个a[0]来计数
    for(int i=1;i<=n;++i)printf("%d ",a[i]);
    printf("\n");
    for(int i=1;(i<<1)<=n;++i)
    {
        temp=a[i];
        a[i]=a[n-i+1];
        a[n-i+1]=temp;
    }
    for(int i=1;i<=n;++i)printf("%d ",a[i]);
    return 0;
}
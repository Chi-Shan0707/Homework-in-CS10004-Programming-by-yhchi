#include<stdio.h>

int main()
{
    int n,a[10002],m;
    scanf(" %d",&n);for(int i=1;i<=n;++i)scanf(" %d",&a[i]);
    scanf(" %d",&m);
    while(m--)
    {
        for(int i=1;i<=n;++i)a[i-1]=a[i];
        a[n]=a[0];
    }
    for(int i=1;i<=n;++i)printf("%d " ,a[i]);
    return 0;
}
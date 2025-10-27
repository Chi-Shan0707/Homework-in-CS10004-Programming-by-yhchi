#include<stdio.h>

int main()
{
    int len,a[10002],n,m;
    scanf(" %d",&len);for(int i=1;i<=len;++i)scanf(" %d",&a[i]);
    scanf(" %d",&n);scanf(" %d",&m);
    while(m--)
    {
        for(int i=1;i<=n;++i)a[i-1]=a[i];
        a[n]=a[0];
    }
    for(int i=1;i<=n;++i)printf("%d " ,a[i]);
    return 0;
}
/*
测试样例：a[]={1,2,3,4,5,6,7,8,9,0}, n=10, m=3; a[]={1,2,3,4,5,6,7,8,9,0}, n=5, m=3。
10
1 2 3 4 5 6 7 8 9 0
10 3

10
1 2 3 4 5 6 7 8 9 0
5 3
*/
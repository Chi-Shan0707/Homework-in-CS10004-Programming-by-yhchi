#include<stdio.h>
const int N=1e5+7;
int main()
{
    int n,ans,len,LAST,NOW;
    int a[N];
    scanf(" %d",&n);
    /*
不用数组是不是不太好
    scanf(" %d",&LAST);     ans=len=1;
    for(;n;--n,LAST=NOW)
    {
        scanf(" %d",&NOW);
        len=(NOW!=LAST)?1:(len+1);
        ans=(ans>len?ans:len);
    }
    printf("%d\n",ans);
    */
    for(int i=0;i<n;++i)scanf(" %d",&a[i]);
    ans=len=1;
    for(int i=1;i<n;++i)
    {
        len=(a[i]!=a[i-1])?1:(len+1);
        ans=(ans>len?ans:len);
    }
    printf("%d\n",ans);
    return 0;
}
/*
a[]={1, 2, 2, 2, 3, 2},
输入 6
1 2 2 2 3 2
b[]={1, 1, 2, 1, 2, 2}，
输入 6
1 1 2 1 2 2
c[]={1,2,3,4,5}。
输入 5
1 2 3 4 5

*/
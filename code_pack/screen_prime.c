#include <stdio.h>
int main() {
    int n;int tag[10001];//true表示素数
    int m,prime[1000];
    printf("Tell me n(n>=2):");
    scanf(" %d", &n);
    tag[0]=tag[1]=0;
    for(int i=2;i<=n;++i)tag[i]=1;
    //埃氏筛
    for(int i=2;i<=n;++i)
    {
        if(tag[i])
        {
            tag[i]=1;
            prime[++m]=i;
        }
        for(int j=1;j<=m&&i*prime[j]<=n;++j)
        {
            tag[i*prime[j]]=0;
//            if(i%prime[j]==0) break;
//            有这行跳出就是欧式筛了嘿嘿
        }
    }
    printf("There are %d primes from 1 to %d \n They are:2",m,n);
    for(int i=2;i<=m;++i)printf(",%d",prime[i]);
    return 0;
}
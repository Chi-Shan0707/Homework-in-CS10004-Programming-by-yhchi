#include<stdio.h>
void solve(const int *ncp,const int a[],const int *sump,int *ansp)
{
    int n=*ncp;
    const int *l,*r;
    int tot;
    for(l=a+1;l!=a+n+1;++l)
    {
        tot=0;
        for(r=l;r!=a+n+1;++r)
        {
            tot+=(*r);
            if(tot==(*sump))
            {
                printf("SubArray %d %d\n",(int)(l-a),(int)(r-a));
                ++(*ansp);
            }
    }
}
}
int main()
{
    int n,a[1003],sum,ans;
    scanf(" %d",&n);
    for(int i=1;i<=n;++i)scanf(" %d",&a[i]);
    scanf(" %d",&sum);ans=0;
    solve(&n,a,&sum,&ans);
    printf("%d\n",ans);
    return 0;
}
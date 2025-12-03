#include<stdio.h>
void is_prime(int x[], int n)
{
    int top=0;
    int flag=1;
    for(int i=2;i<=100000;++i)
    {
        flag=1;
        for(int j=2;j*j<=i;++j)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)x[++top]=i;
        if(top==n)break;
    }
}
int main()
{
    int n,ans[10002];
    scanf(" %d",&n);
    is_prime(ans,n);
    for(int i=1;i<=n;++i)
    {
        printf("%d ",ans[i]);
        if(i%10==0)printf("\n");    
    }
    return 0;
}
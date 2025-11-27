#include<stdio.h>
int main()
{
    int l,r,mid,rk;
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
//    for(int i=1;i<=n;++i)printf("%d ",a[i]);
    printf("\n");
 
    for(int i=1;i<=n;)
    {
        a[++a[0]]=a[i];
        while(a[i]==a[a[0]])++i;
    }
    n=a[0];

//    for(int i=1;i<=n;++i)printf("%d ",a[i]);
    printf("我们定义val（val在原数组内）序号为：去重后数组中小于val的数的个数+1\n");
    while(1)
    {
        int val;scanf(" %d",&val);
        if(val==-404)break;
        l=1;r=n;
        rk=-1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(a[mid]==val)
            {
                rk=mid;
                break;
            }
            else if(val<a[mid])r=mid-1;
            else l=mid+1;
        }
        if(rk==-1)printf("%d not found\n",val);
        else printf("%d is Number %d.\n",val,rk);
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int n;
    int p[10002],vst[100002],a[20];
    //2^20>1000*1000,最多的就是很多个2
    //素数密度1/ln(n)
    //总而言之，非常保险，数组大小肯定够用
    printf("输入正整数<=1000000\n");
    scanf(" %d",&n);
    if(n==1){printf("1=1");return 0;}
    for(int i=0;i<=n;++i)vst[i]=0;
    a[0]=p[0]=0;
//初始化数组第0号足矣
/*
欧式筛:原理很简单，让埃氏筛minus重复遍历：每个数只被其最小素因数带过
*/
    for(int i=2;i<=n;++i)
    {
        if(!vst[i]){p[++p[0]]=i;}
        vst[i]=1;
        for(int j=1;j<=p[0]&&(i*p[j])<=n;++j)
        {
            vst[i*p[j]]=1;
            if(i%p[j]==0){break;}
        }
    }
    printf("%d",n);   
//    for(int i=1;i<=p[0];++i)printf("%d ",p[i]);
    for(int i=1;i<=p[0];++i)
    {
        while(n%p[i]==0)
        {
            n/=p[i];
            a[++a[0]]=p[i];
        }
    }
    printf("=%d",a[1]);
    for(int i=2;i<=a[0];++i)printf("*%d",a[i]);
    return 0;
}
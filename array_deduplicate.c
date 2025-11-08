#include<stdio.h>
#define N 1000
//为什么不能define N 1e5+7因为这是浮点常量，不能用来定义数组
int main()
{
    int n,a[N],b[N],m;
    scanf(" %d",&n);
    for(int i=0;i<n;++i)scanf(" %d",&a[i]);
    for(int i=0;i<n;++i)
    {
        if(m==0)b[m++]=a[i];
        else
        {
//            bool unique=true;
             int unique=1;
            for(int j=0;j<m;++j)
            {
                if(b[j]==a[i])
                {
                    //unique=false;
                    unique=0;
                    break;
                }
            }
            if(unique)b[m++]=a[i];
        }
    }
    for(int i=0;i<m-1;++i)printf("%d,",b[i]);printf("%d",b[m-1]);
    return 0;
}
/*
输入：
5
1 2 3 2 1
输出：
1,2,3

输入：
7
1 1 2 1 1 3 4
输出：
1,2,3,4
*/
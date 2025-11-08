#include<stdio.h>
int main()
{
    int n;scanf("%d",&n);
    if(n<=0){printf("Invalid input");return 0;}
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=2*n-1;++j)
        {
            if(i==1)printf("*");
            else
            {
                if(j==i||j==2*n-i)printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
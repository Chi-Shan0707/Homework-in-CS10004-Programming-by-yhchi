#include<stdio.h>
int main()
{
    for(int i=31;i<=126;++i)
    {
        if((i-31)%10==0)printf("\n");
        printf("%c(%3d)",i,i);
    }
    return 0;
}
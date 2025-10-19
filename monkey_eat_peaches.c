#include<stdio.h>
int main()
{
    int tot=0;
    for(int day=5;day>=1;--day)
    {
        tot=(tot+1)<<1;
    }
    printf("There are %d peaches initially.\n",tot);
    for(int day=1;day<=5;++day,tot=(tot>>1)-1)
    {
        printf("Day%d:A monkey eats %2d peaches.There are %2d peaches left.\n",day,(tot>>1)+1, (tot>>1)-1);
    }
    return 0;
}
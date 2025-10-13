#include<stdio.h>
int main()
{
    int mode;printf("mode=1:while/mode=2:for\n");scanf("%d",&mode);printf("Narcissistic numbers in [100,999]:");
    int i=100;int a,b,c,num;
    switch(mode)
    {
        case 1:
            do
            {
                a=i/100,b=(i%100)/10,c=i%10;
                num=a*a*a+b*b*b+c*c*c;
                if(num==i)
                {
                    printf("%d ",i);
                }
                ++i;
            }while (i<=999);
            break;
        case 2:
            for(i=100;i<=999;++i)
            {
                a=i/100,b=(i%100)/10,c=i%10;
                num=a*a*a+b*b*b+c*c*c;
                if(num==i)
                {
                    printf("%d ",i);
                }
            }
            break;
        default:
            printf("Invalid input");
            break;
    }
    return 0;
}
#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long i,j=1;
    int s=1;
    //s为符号
    double pi=4,t=4;
    int k=0;
    double target[100]={3.14,3.141,3.1415,3.14159,3.141592,3.1415926,3.14159265,3.141592653,3.1415926535};
//想太多了，之后精度会爆掉，肯定会爆掉
    //15358947;
    unsigned long base=100;
    double ERROR=0.005;
    for(i=1;fabs(t)>1e-8;++i)
    {
        s^=1;
        t=(s)?(4.0/(j+=2)):(-4.0/(j+=2));//和j++一样，返回左值再递增
        pi+=t;
        if((int)(pi*base-target[k]*base)==0&&fabs(pi-target[k])<ERROR)
        {
            switch(k)
            {
                case 0:
                    printf("计算到第%d项时得到数值%.2lf:\n",i+1,pi);
                    break;
                case 1:
                    printf("计算到第%d项时得到数值%.3lf:\n",i+1,pi);
                    break;
                case 2:
                    printf("计算到第%d项时得到数值%.4lf:\n",i+1,pi);
                    break;
                case 3:
                    printf("计算到第%d项时得到数值%.5lf:\n",i+1,pi);
                    break;
                case 4:
                    printf("计算到第%d项时得到数值%.6lf:\n",i+1,pi);
                    break;
                case 5:
                    printf("计算到第%d项时得到数值%.7lf:\n",i+1,pi);
                    break;
                case 6:
                    printf("计算到第%d项时得到数值%.8lf:\n",i+1,pi);
                    break;
                case 7:
                    printf("计算到第%d项时得到数值%.9lf:\n",i+1,pi);
                    break;
                case 8:
                    printf("计算到第%d项时得到数值%.10lf:\n",i+1,pi);
                    break;
                case 9:
                    printf("计算到第%d项时得到数值%.11lf:\n",i+1,pi);
                    break;
                case 10:
                    printf("计算到第%d项时得到数值%.12lf:\n",i+1,pi);
                    break;
            }
            ERROR/=10.0;
            base*=10;
            ++k;
        }
    }
    printf("PI=%.8lf\n",pi);
    //理论上，15~16 位有效数字，但我不想等
    return 0;
}

                  /*

                  曾经的幻想
                */

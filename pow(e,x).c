#include<stdio.h>
#include<math.h>
int main()
{
    double x,X;//x与x的累乘法
    double i;
    double facorial;//阶乘
    double res;
    scanf(" %lf",&x);
    res=1.00;
    X=1.00;
    facorial=1.00;
//泰勒展开,x属于R
    for(i=1.0;;++i)
    {
        facorial*=i;
        X*=x;
        if(fabs(X/facorial)<0.000001)break;
//大部分人都会忘记这里x属于R，x有负值可以取
        res+=(X/facorial);
    }   
    printf("%.6lf\n",res);
    return 0;
}
#include <stdio.h>
double add(double a, double b){return a+b;}
double sub(double a, double b){return a-b;}
double mul(double a, double b){return a*b;}
double div(double a, double b){return a/b;}
double execute(double a, double b, double (*operation)(double, double))
{
    return operation(a, b);
} 
int main(){
    double a, b;int  c;
    printf("1 add\n2 sub\n3 mul\n4 div\n");
    scanf(" %lf %lf %d",&a,&b,&c);
    double (*op)(double, double)=0;
    switch (c)
    {
        case 1:
            op=add;
            break;
        case 2:
            op=sub;
            break;
        case 3:
            op=mul;
            break;
        case 4:
            op=div;
            break;
    }
    double res=execute(a,b,op);
    printf("%lf\n", res);
    return 0;
}

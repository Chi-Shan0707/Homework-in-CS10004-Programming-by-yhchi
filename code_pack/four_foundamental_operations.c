#include<stdio.h>
float n,m;
int main()
{
    scanf("%f%f",&n,&m);
    printf("和");
    printf("%f",n+m);
    printf("\n");
    printf("差");
    printf("%f",n-m);
    printf("\n");
    printf("积");
    printf("%f",n*m);
    printf("\n");
    printf("商");
    printf("%f",n/m);
    printf("\n");
    printf("余");
    int _n,_m;
    _n=(int)n; _m=(int)m;
    printf("%d",_n%_m);
    return 0;
}
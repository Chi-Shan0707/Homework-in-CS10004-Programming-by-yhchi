#include<stdio.h>
int i,j,k;long u;
float x,y,z;
char c1,c2;
int main()
{
    i=1,j=2,k=3,u=47215L;
    x=2.2,y=3.4,z=-5.6;
    c1='a',c2='b';
    printf("i=%d     j=%d     k=%d \n",i,j,k);
    printf("x=%.5f,y=%.5f,z=%.5f\n",x,y,z);
    printf("x+y=%.2f  y+z=%.2f  z+x=%.2f\n",x+y,y+z,z+x);
//.2控制位数
    printf("u=%ld\n",u);;
    printf("c1='%c' or %d(ASCLL)   c2=%c or %d(ASCLL)\n",c1,c1,c2,c2);
    return 0;
}
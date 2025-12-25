#include<stdio.h>
int main(){
int a=8,b=9;
float x=127.895,y=-123.456; 
char c='B';long n=12345678L;unsigned u=65535u; 
printf ("%d,%d\n",a,b); 
printf ("%5d,%5d\n",a,b);
printf ("%f,%f\n",x,y);
printf ("%-12f,%-12f\n",x,y); 
printf ("%8.3f,%8.3f,%.3f,%.3f,%4f,%5f\n",x,y,x,y,x,y);
printf ("%e,%10.4e\n",x,y); 
printf ("%c,%d,%o,%x\n",c,c,c,c);
printf ("%ld,%lo,%lx\n",n,n,n);
printf ("%u,%o,%x,%d\n",u,u,u,u); 
printf("%s,%6.3s,%-10.5s\n","C language","C language","C language");
return 0; 
}

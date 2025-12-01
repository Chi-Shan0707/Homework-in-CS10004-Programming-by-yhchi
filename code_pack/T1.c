#include <stdio.h>
int a[10];
int b[][3] = {{1, 0, 0}, {4, 2, 0}};
int *p[2];
int (*q)[3] = b;
int (*u)(int, int);
int *v(int, int);
int *(*w)(int, int);
int add(int x, int y){return x + y;}
int *mulp(int x, int y){static int r; r = x * y; return &r;}
int main(){
p[0] = &a[0]; p[1] = &a[1];
u = add; w = mulp;
printf("%d\n", u(2, 3));
printf("%d\n", *w(2, 3));
printf("%d %d\n", q[0][0], q[0][1]);
return 0;
}
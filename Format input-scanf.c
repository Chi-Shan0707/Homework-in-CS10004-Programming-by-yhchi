#include<stdio.h>
int main()
{
    int i;char c;long k;float f;double x;
//    i=2,c='B',k=123456,f=5.8,x=3.4;
/*
input：
i=2 c=B
k=123456
f=5.8 x=3.4
*/
    scanf("i=%d c=%c",&i,&c);
    getchar();
    scanf("k=%ld",&k);
    getchar();
    scanf("f=%f x=%lf",&f,&x);
    getchar();
    printf("i=%d c=%c k=%ld f=%f x=%lf",i,c,k,f,x);
/*
scanf为格式化输入，会按照双引号内的格式去匹配输入的字符串。
它不在意"i=%d c=%c"间的空格数量，但很在意其他字符匹配，以及两个scanf间是否有空格。
从本质上讲，我们从键盘输入的数据并没有直接交给 scanf()，而是放入了缓冲区中，直到
我们按下回车键（输入换行符），scanf() 才到缓冲区中读取数据。
如果缓冲区中的数据符合 scanf() 的要求，那么就读取结束；
如果不符合要求，那么就继续等待用户输入，或者干脆读取失败。
所以这里要用getchar()读掉换行符/空格。
*/
    return 0;
}
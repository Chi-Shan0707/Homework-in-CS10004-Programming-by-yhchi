#include<stdio.h>
int main()
{
    int a=8,b=9;float x=127.895,y=-123.456;char c='B';long n=12345678L; unsigned u=65535u;
    printf("%d,%d\n",a,b);//输出整数a,b
    printf("%5d,%5d\n",a,b);//右对齐5字宽
    printf("%f,%f\n",x,y);//输出float x y
    printf("%-12f,%-12f\n",x,y);//左对齐  共宽12
    //由于二进制小数精度问题，所以未明确保留几位就有误差
    //127.894997  ,-123.456001
    printf("%8.3f,%8.3f,%.3f,%.3f,%4f,%5f\n",x,y,x,y,x,y);//  负号占用一格
    printf("%e,%10.4e\n",x,y);//科学计数法
    printf("%c,%d,%o,%x\n",c,c,c,c);//c作为字符输出；之后按照不同进制输出整数
    printf("%ld,%lo,%lx\n",n,n,n);//数过大，要l类型
    printf("%u,%o,%x,%d\n",u,u,u,u);
    printf("%s,%6.3s,%-10.5s\n","c language","c language","c language");//%s输出字符串，%s6表示总宽，.3是取前3个字符
    return 0;
}
/*
output:
8,9
    8,    9
127.894997,-123.456001
127.894997  ,-123.456001
 127.895,-123.456,127.895,-123.456,127.894997,-123.456001
1.278950e+002,-1.2346e+002
B,66,102,42
12345678,57060516,bc614e
65535,177777,ffff,65535
c language,   c l,c lan
*/
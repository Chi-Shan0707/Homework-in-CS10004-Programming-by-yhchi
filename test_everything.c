#include <stdio.h>

int main() {
    int j,i;
    double k;
    j=2;
    k=-2.4;
    printf("%d\n",(int)(k));
    printf("%d",j++);
    
    i=j+=2;
    printf("%d ",i);
  //  scanf("%d", &j);
 //   for(int i=0;i<40;++i)printf("%d",i);
    int a[10];
    a[1]=10;
    printf("%d",&a[1]);
    // printf("\n");
    // // 输出字符 'A'，并指定字段宽度为10
    // printf("%*c\n", 10, 'A');
    
    // // 输出字符 'B'，并指定字段宽度为5
    // printf("%*c\n", 5, 'B');
    
    // // 输出字符 'X'，并指定字段宽度为1（实际上就是普通输出）
    // printf("%*c\n", 1, 'X');
    // printf("j=%5d\n",j);
/*
%*c 格式说明符：

%c 是输出单个字符的格式说明符
* 表示字段宽度由参数指定
所以 %*c 的含义是：输出一个字符，但该字符占据的宽度由参数指定

所以之后会增加一个参数
*/
    
//    printf("\nstart");
  //  printf("%*c",j,' ');
    //printf("end");
   // char c='376';
   // printf("%d",c);
    return 0;
}
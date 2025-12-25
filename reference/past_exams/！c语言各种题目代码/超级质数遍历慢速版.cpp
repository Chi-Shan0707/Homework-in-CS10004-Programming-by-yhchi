#include "stdio.h"
#include "math.h"
int prime(int n){//判断素数,素数返回0,否则返回1
    int i;
    if(n>2 && !(n&1) || n<2)
        return 1;
    for(i=3;i*i<=n;i+=2)
        if(!(n%i))
            return 1;
    return 0;
}
int main(int argc,char *argv[]){
    int n,i,t,nn;
    printf("Input n(int n>1)...\nn=");
    if(scanf("%d",&n)!=1 || n<2){
        printf("Input error, exit...\n");
        return 0;
    }
    nn=n;
    n=pow(10,n);
    for(i=2;i<=n;i++){
        for(t=i;t;t/=10)//从低位删除0位,1位...直到只剩1位都是素数的为超级素数
            if(prime(t))
                break;
        if(!t&&i<pow(10,nn)&&i>pow(10,nn-1))
            printf("%d ",i);
    }
    printf("\n");
    return 0;
}

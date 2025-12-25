#include <stdio.h>
int main(){
	int i,n,sum=0,p;
	scanf("%d",&i);
	for(n=1;n*(n+1)/2<i;n++)
		p=n,sum+=n*n;
	sum+=(p+1)*(i-p*(p+1)/2);
	printf("%d",sum);
	return 0;
}

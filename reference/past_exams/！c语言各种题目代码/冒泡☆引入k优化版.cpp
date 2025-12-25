#include<stdio.h>
#define n 10
int main(){
	int a[10]={1,3,2,4,100,4,10,9,71,10};
	int i,j,t,k;
	for (i=0;i<=n-2;i++){
		k=0;
		for (j=n-1;j>i;j--){
			if (a[j-1]>a[j])
				t=a[j],a[j]=a[j-1],a[j-1]=t;
				k=j;
		}
		i=k;
	}
	for (int k=0;k<=9;k++) printf("%d,",a[k]);
}

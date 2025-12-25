#include<stdio.h>
int main(){
	int a[10]={2,3,4,5,1,6,7,9,8,0};
	int i,j,k,t;
	for (i=0;i<=10;i++){
		for (j=i+1;j<10;j++){
			if (a[i]>a[j])
			t=a[i],a[i]=a[j],a[j]=t;
		}
	}
	for (k=0;k<=9;k++){
		printf("%d,",a[k]);
	}

	return 0;
}

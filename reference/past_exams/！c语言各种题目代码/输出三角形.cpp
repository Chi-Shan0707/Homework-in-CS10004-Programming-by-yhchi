#include<stdio.h>
int main(){
	int n,i,j;
	int a[100][100] = {0};
	scanf("%d",&n);
	for (i=0;i<n;i++){
		for (j=n-i-1;j<n;j++)
			a[i][j]=i*(i+1)/2+j-n+i+2; 
	}
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (a[i][j]==0)
				printf("   ");
			else
				printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}

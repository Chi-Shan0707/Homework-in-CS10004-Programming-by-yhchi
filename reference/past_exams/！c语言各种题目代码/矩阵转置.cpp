#include<stdio.h>
int main(){
	int a[2][3]={1,2,3,4,5,6};
	int b[3][2]; 
	int i,j,m;
	for (i=0;i<2;i++){
		for(j=0;j<3;j++){
			b[j][i]=a[i][j];
		}
	}
	for(m=0;m<6;m++)
	printf("%d",b[0][m]);
	return 0;
}

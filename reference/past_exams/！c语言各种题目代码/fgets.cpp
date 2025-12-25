#include<stdio.h>
int main(){
	char a[100];
	fgets(a,5,stdin);//只保留前4个存进a中 
	printf("%s",a);
	return 0;
}

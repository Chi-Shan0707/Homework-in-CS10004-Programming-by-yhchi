#include<stdio.h>
int main(){
	int input,i;
	scanf("%d",&input);
	while(input%10==0)
		input/=10;
	while(input!=0){
		i=input%10;
		input/=10;
		printf("%d",i);
	}
	return 0;
}

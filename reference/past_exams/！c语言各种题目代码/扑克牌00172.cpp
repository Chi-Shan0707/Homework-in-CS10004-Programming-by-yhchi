#include <stdio.h>
#include <string.h>
int number(char *input){
	if(input[0]>='3'&&input[0]<='9')
		return input[0]-'0';
	else if (strlen(input)==2)
		return 10;
	else if (input[0]=='2')
		return 15;
	else if (input[0]=='J')
		return 11;
	else if (input[0]=='Q')
		return 12;
	else if (input[0]=='K')
		return 13;
	else if (input[0]=='A')
		return 14;
}
int huase(char *i){
	if (strcmp(i,"ºìÐÄ")==0)
		return 3;
	else if (strcmp(i,"ºÚÌÒ")==0)
		return 4;
	else if (strcmp(i,"·½¿é")==0)
		return 2;
	else return 1;
}
int main(){
	char apre1[3],bpre1[3],apre2[3],bpre2[3];
	int a1,a2,b1,b2,r; 
	scanf("%s%s%s%s",apre1,bpre1,apre2,bpre2);
	a1=number(apre1);
	a2=number(apre2);
	b1=huase(bpre1);
	b2=huase(bpre2);
	if (a1>a2)
		r=1;
	else if (a1<a2)
		r=-1;
	else {
		if (b1>b2)
			r=1;
		else if (b1<b2)
			r=-1;
		else r=0;
	}
	printf("%d",r);
	return 0;
}

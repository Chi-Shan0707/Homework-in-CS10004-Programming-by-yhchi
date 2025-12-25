#include<stdio.h>
#include<string.h>
void bubble(char*a){
	int i,j,temp,n;
	n=strlen(a);
	for (i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}

void sort(char*a){
	char n[500],l[500],u[500];
	int ni=0,li=0,ui=0,i,len=strlen(a);
	for (i=0;i<len;i++)
	{
		if (a[i]>='0'&&a[i]<='9')
		{
			n[ni]=a[i];
			ni++;
		}
		if (a[i]>='a'&&a[i]<='z')
		{
			l[li]=a[i];
			li++;
		}
		if (a[i]>='A'&&a[i]<='Z')
		{
			u[ui]=a[i];
			ui++;
		}
	}
	n[ni]='\0';l[li]='\0';u[ui]='\0';
	bubble(n);bubble(l);bubble(u);
	int ai=0;
	for (i=0;n[i]!='\0';i++)
	{
		a[ai++]=n[i];
	}
	for (i = 0; l[i] != '\0'; i++) {
        a[ai++] = l[i];
    }
    for (i = 0; u[i] != '\0'; i++) {
        a[ai++] = u[i];
    }
	a[ai]='\0';
}

void print(char*a){
	int i,n;
	n=strlen(a);
	if (n%2==1){
		for (i=0;i<n;i+=2){
			printf("%c",a[i]);
		}
		for (i=n-2;i>=0;i-=2){
			printf("%c",a[i]);
		}	
	}
	if (n%2==0){
		for (i=0;i<n;i+=2){
			printf("%c",a[i]);
		}
		for (i=n-1;i>=0;i-=2){
			printf("%c",a[i]);
		}	
	}	

}
int main(){
	char a[501],*p;
	gets(a);
	sort(a);
	print(a);
	return 0;
}

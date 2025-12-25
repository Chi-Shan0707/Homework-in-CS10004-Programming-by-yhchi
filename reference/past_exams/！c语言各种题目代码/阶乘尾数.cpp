#include<stdio.h>
int main()
{
	int n,a,i;
	scanf("%d",&n);
	a=1;
	for(i=1;i<=n;i++)
	{
		a*=i;
		while(a%10==0)
		{
		a/=10;
	    }
	    a%=100;
	}
	printf("%d",a%10);
	return 0;
 } 

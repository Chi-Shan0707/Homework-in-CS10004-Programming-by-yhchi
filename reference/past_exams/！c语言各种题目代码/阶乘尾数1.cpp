#include<stdio.h>
int main()
{
	int n,a,b,c=0,p[100],q[100];
	int i=1;
	scanf("%d",&n);
	a=1;
	while(i<=n)
	{
		a=a*i;
		while(a%10==0)
		{
		a=a/10;
	    }
	    a=a%100;
	    b=a%10;
	    p[i-1]=b;
	    i+=1;
	}
	i=1,a=1;
		while(i<=n)
	{
		a=a*i;
		while(a%10==0)
		{
		a=a/10;
	    }
	    a=a%1000;
	    b=a%10;
	    q[i-1]=b;
	    i+=1;
	}
	for(i=0;i<n;i++)
	{
		c+=(p[i]-q[i])*(p[i]-q[i]);
	}
	printf("%d %d",a%10,c);
	return 0;
 } 

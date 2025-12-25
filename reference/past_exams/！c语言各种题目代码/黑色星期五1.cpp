#include<stdio.h> 
int main()
{
	int y0,y,flag,n,N,d,a,i,k;
	y0=1998,flag=n=N=k=0,i=1;
	scanf("%d",&y);
	if((y%4==0 and y%100!=0)or(y%400==0))
	flag=1;
	while(y0<y)
	{
		if((y0%4==0 and y0%100!=0)or(y0%400==0))
		{
		n+=1;
		}
		y0+=1; 
	}
	N=y-1998-n;
	d=365*N+366*n;
	a=d%7+4;
	while(i<31)
	{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
	if(flag==0)
	{
	while(i<28)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	    }
    }	
	if(flag==1)
	{
		while(i<29)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	    }
    }
	i=1,a+=1;
		while(i<31)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<30)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<31)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<30)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<31)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<31)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<30)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<31)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<30)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	i=1,a+=1;
		while(i<31)
		{
	    if(a>7)
	    a=a-7;
	    if(i==13 and a==5)
	    {
		k+=1;
	    }
	    a+=1;
	    i+=1;
	}
	printf("%d",k);
	return 0;
	}

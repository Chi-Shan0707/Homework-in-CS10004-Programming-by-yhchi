#include<stdio.h> 
int main(){
	int y0,y,flag,n,N,d,a,i,k;
	y0=1998,flag=n=N=k=0;
	scanf("%d",&y);
	if((y%4==0 and y%100!=0)or(y%400==0))
		flag=1;
	//flag=1为闰年	
	
	while(y0<y){
		if((y0%4==0 and y0%100!=0)or(y0%400==0)){
			n++;
	    }	
		y0++;
	}
	//n=y-y0中的闰年个数，N为365天年数
	
	
	N=y-y0-n;
	d=365*N+366*n;
	a=d%7+4;
	while(i<31)
	{
		
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
		a+=1;
	    i+=1; 
	}
	i=1;
	if(flag=0)
	{
	while(i<28)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
}	
	else
		while(i<29)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<31)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<30)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<31)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<30)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<31)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<31)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<30)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<31)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<30)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	i=1;
		while(i<31)
		{
		a+=1;
	    if(a>7)
	    a=1;
	    if(i==13 and a==5)
	    k+=1;
	    i+=1;
	}
	printf("%d",k);
	return 0;
}

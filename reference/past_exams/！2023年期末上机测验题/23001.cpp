#include<stdio.h>
int yes(int x)
{
	int count[10]={0};
	int i;
	while(x!=0)
	{
		count[x%10]++;
		x/=10;
	}
	for (i=0;i<10;i++)
	{
		if (count[i]==0||i==count[i])
			continue;
		else
			return 0;
	}	
	return 1;
}
int main(){
	int n,i;
	scanf("%d",&n);
	for (i=n+1;;i++)
	{
		if (yes(i)==1)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}

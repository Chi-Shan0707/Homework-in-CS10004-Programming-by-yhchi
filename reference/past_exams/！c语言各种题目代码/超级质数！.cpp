#include<stdio.h>
#define N 8

int test(int n)
{
	int i;
	for (i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}		
	}
	return 1;
}

int main()
{
	int a[N][1000] = {2,3,5,7};
	int c[4] = {1,3,7,9};
	int i,j,k,num,m,n;
	for(i = 0; i < N-1; i++)
	 {
	 	n=0;
		for(j = 0;a[i][j] != 0;j++) 
		{
			for(k = 0;k <4;k++)
			{
				num = a[i][j]*10+c[k];
				if(test(num)) 
				{
					a[i+1][n] = num;
					n++;
				}
			}
		}
	}
	printf("Enter m:");
	scanf("%d", &m);
	for(i = 0;a[m-1][i] != 0;i++)
	{
	printf("%d\t",a[m-1][i]);
	}
	return 0;
 } 

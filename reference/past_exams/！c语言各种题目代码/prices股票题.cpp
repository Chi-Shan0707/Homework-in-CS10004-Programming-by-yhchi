#include<stdio.h>
int benefit(int prices[], int n){
	int max=0, up, i, j;
	for (i = 0;i <= n - 2; i++){
		up =prices[i+1];
		for (j=i+1;j<=n-1;j++){
			if prices[j]>up
				up = prices[j];
		}
		if (max < up - prices[i])
			max = up - prices[i];
	}
	return max;
}

int main(){
	int n1;
	int prices[10];
	while ()
	printf("%d",benefit(prices));
	return 0;
}

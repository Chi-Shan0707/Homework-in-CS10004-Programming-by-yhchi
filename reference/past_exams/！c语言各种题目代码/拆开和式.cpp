#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
int a[MAXSIZE];

void partition(int i, int k) 
{
    if (i == 0) 
	{
        printf("%d =", a[k - 1]);
        for (int j = 1; j < k; j++) 
		{
            printf(" %d", a[j]);
            if (j != k - 1) 
			{
                printf(" +");
            }
        }
        printf("\n");
        return;
    }
    for (int j = (a[k - 1] < i ? a[k - 1] : i); j > 0; j--) 
	{
        a[k] = j;
        partition(i - j, k + 1);
    }
}

int main() {
    int n;
    printf("Input a Positive Integer --> ");
    scanf("%d", &n);
    a[0] = n;
    partition(n, 1);
    return 0;
}


/*Ò¶ÐÇº£_23307130141*/ 
#include <stdio.h>
#include <string.h>
void det(char*a)
{
	int i,n=strlen(a),j;
	for (i=0;i<n;i++)
	{
		while (i>=0&&a[i]==a[i+1])
		{
			for (j=i;a[j+2]!='\0';j++)
			{
				a[j]=a[j+2];
			}
			a[j]='\0';
			i--;			
		}
	}
}

int main() {
	char a[100];
	gets(a);
	det(a);
	puts(a);
    return 0;
}

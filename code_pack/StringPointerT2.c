#include<stdio.h>
void swap(char **s1,char **s2)
{
    char *temp=*s1;
    *s1=*s2;
    *s2=temp;
}
int main()
{
    char s1[100]="";
    char s2[100]="";
    char *p1=s1;
    char *p2=s2;
    scanf(" %s",p1);
    scanf(" %s",p2);
    swap(&p1,&p2);
    printf("%s \n%s\n",p1,p2);
    return 0;
}
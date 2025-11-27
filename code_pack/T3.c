#include<stdio.h> 
int main()
{
   char str[1002];
   scanf("%s",str);
   char *hd;char *tl;
   char *ptr;
   hd=str;
   tl=str;
   ptr=str;
   ++ptr;
    while(*ptr!='\0')
    {
        ++tl;
        ++ptr;
    }
    while(*hd!='\0')
    {
        if(*hd!=*tl)
        {
            printf("not");
            return 0;
        }
        ++hd;
        --tl;
    }
    printf("ys");
    return 0;
}
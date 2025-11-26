#include<stdio.h> 
#include<string.h>
char str[]="ABC";
void pp(char *s,int k)
{
  int i;char c;
  if(k==0)printf("%s\n",s);
  else
  {
    for(i=k-1;i>=0;i--)
    {
      c=s[k-1];s[k-1]=s[i];s[i]=c;
      pp(s,k-1);
      c=s[k-1];s[k-1]=s[i];s[i]=c;
    }
  }
}
int main()
{
  pp(str,strlen(str));
  return 0;
}
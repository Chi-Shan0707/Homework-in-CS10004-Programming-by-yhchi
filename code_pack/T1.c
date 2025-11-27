#include<stdio.h>
#include<string.h>
int ans,n;
char str[12];//char str[]
void input()
{
    scanf("%s",str);
}
void convert()
{
    int len;int i;
    for(len=0;str[len]!='\0';++len);
    n=0;
    for(i=len-1;i>=0;--i)
    {
        int digit;
        if('0'<=str[i]&&str[i]<='9')digit=str[i]-'0';
        else if('A'<=str[i]&&str[i]<='F')digit=str[i]-'A'+10;
        else digit=str[i]-'a'+10;
        n=(n<<3)+(n<<1)+digit;
    }
}
void Maxprime()
{
    int i=2;
    for(ans=n-1;ans>=2;--ans)
    {
        int flag=1;
        for(i=2;i*i<=ans;++i)
        {
            if(ans%i==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            return;
        }
    }
}
void output()
{
    printf("%d",ans);
}
int main()
{
    input();
    convert();
    Maxprime();
    output();
    return 0;
}
#include<stdio.h>
void swap(int *x,int* y)
{
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
}
void flip(int n,int a[][100])
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            swap(&a[i][j],&a[j][i]);
        }
    }
}
int cal_len(char *s)
{
    int len=0;
    while(*s!='\0')++s,++len;
    return len;
}
void copy(int n,char *src,char *dest)
//source,destination
{
    
    char *read;
    char *write;
    read=src;
    write=dest;
    while(n--&&*read!='\0')
    {
     //   printf("%c , ",*read);
        *write=*read;
        ++read;
        ++write;
    }
   // *write='\0';
}
void convert(char *str)
{
    char *p=str;
    while(*p!='\0')
    {
        if(*p>='a'&&*p<='z')*p=*p-'a'+'A';
        ++p;
    }
}
void organize(char *str)
{
    char res[100]="";
    char* hd;
    char* tl;
    char* ptr;
    hd=tl=str;
    ptr=res;
    while(*hd!='\0')
    {
       while(*hd==' '&&*hd!='\0')
        {
            ++hd;
            ++tl;
        }
        while(*tl!=' '&&*tl!='\0')
        {
            *ptr=*tl;
            ++ptr;
            ++tl;
        }
        *ptr=' ';
        ++ptr;
        hd=tl;
    }
    *ptr='\0';
    copy(cal_len(res),res,str);
     
}
int main()
{
    int a[100][100];
    int n,len1;
    char s1[1002]="";
    char s2[1002]="";
     printf("请输入字符串:\n");
    
 
    fgets(s1,sizeof(s1),stdin);
     organize(s1);
    printf("func 6\n%s\n****************************\n",s1);
   
    
    //
    //
   
    return 0;
}
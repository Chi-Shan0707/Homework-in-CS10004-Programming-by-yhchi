#include<stdio.h>
#include<string.h>
# define M 100
typedef struct
{
    char word[2000];     /*单词名*/
    int count;             /*单词计数器*/
}KeyTab;
KeyTab tab[M];
int n;
void print()
{
    printf("--------------------------------\n");
    for(int k=1;k<=n;++k)
    {
        printf("%s : %d\n",tab[k].word,tab[k].count);
    }
    printf("--------------------------------\n");
}
void query(char myword[])
{
    for(int i=1;i<=n;++i)
    {
        if(strcmp(myword,tab[i].word)==0)
        {
            tab[i].count++;
            return;
        }
    }
    ++n;
    tab[n].count=1;
    strcpy(tab[n].word,myword);//这里不能直接赋值，这里是两个数组
}
int main()
{
    char myword[100];
    while(1)
    {
        scanf("%s",myword);
        query(myword);
        print();
    }    
    return 0;
}

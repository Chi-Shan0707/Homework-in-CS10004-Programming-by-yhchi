#include <stdio.h>
void query(const int a[][5],int id)
{
    printf("Student %d: ",id);
    for(int i=1;i<5;++i)
    {
        printf("%d ",a[id][i]);
    }
    printf("\n");
}
void print(const int a[][5],int n)
{
   for(int i=0;i<n;++i)
   {
    printf("Student %d: ",i);
        for(int j=1;j<5;++j)printf("%d ",a[i][j]);
        printf("\n");
   }
}
int main()
{
    int table[3][5];
    for(int i=0;i<3;++i)
    {
        table[i][0]=i;
        for(int j=1;j<5;++j)table[i][j]=i*i-j+i*9;
    }
    query(table,1);
    print(table,3);
    return 0;
}

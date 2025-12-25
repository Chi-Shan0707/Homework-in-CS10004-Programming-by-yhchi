#include<stdio.h>
void input(const int n,int *a[])
{
    for(int i=0;i<n;++i)
    {
        int val;
        scanf("%d",&val);
        (*a[i])=val;
//a指向的是某个地址，无法通过const指针地址来修改地址存储的值，
    }
}
void output(const int n,int *a[])
{
    for(int i=0;i<n;++i)
    {
        printf("%d ",(*a[i]));
    }
    printf("\n");
}
void sort(const int n,int *a[])
{
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<n-1-i;++j)
        {
            if((*a[j])>(*a[j+1]))
            {
                int *temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
   int n;
   int x[102];
   int* xp[102];
    scanf(" %d",&n);
    for(int i=0;i<n;++i)xp[i]=x+i;
    input(n,xp);
    sort(n,xp);
    output(n,xp);
    return 0;
}
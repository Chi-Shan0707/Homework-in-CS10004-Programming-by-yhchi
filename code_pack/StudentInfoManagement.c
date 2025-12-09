#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 32
#define MAX_ID_LEN 32
#define COURSE_COUNT 3

typedef struct
{
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    float score[COURSE_COUNT];
    float total;
}Student;

void input_students(Student s[],int *pn)
{
    int n;
    scanf("%d",&n);
    if(n>MAX_STUDENTS) n=MAX_STUDENTS;
    *pn=n;
    for(int i=0;i<n;i++)
    {
        s[i].total=0.0f;
        scanf("%s",s[i].id);
        scanf("%s",s[i].name);
        for(int j=0;j<COURSE_COUNT;j++)
        {
            scanf("%f",&s[i].score[j]);
            s[i].total+=s[i].score[j];
        }
    }
}

void print_student(const Student *p)
{
    printf("%s %s",p->id,p->name);
    for(int j=0;j<COURSE_COUNT;j++) printf(" %.2f",p->score[j]);
    printf(" %.2f\n",p->total);
}

void average_of_course(const Student s[],int n)
{
    int c;
    scanf("%d",&c);
    if(c<1||c>COURSE_COUNT)
    {
        printf("invalid course\n");
        return;
    }
    c--;
    if(n==0)
    {
        printf("no data\n");
        return;
    }
    float sum=0.0f;
    for(int i=0;i<n;i++) sum+=s[i].score[c];
    printf("%.2f\n",sum/n);
}

void total_of_one(const Student s[],int n)
{
    char key[MAX_NAME_LEN];
    scanf("%s",key);
    for(int i=0;i<n;i++)
    {
        if(strcmp(s[i].name,key)==0||strcmp(s[i].id,key)==0)
        {
            printf("%.2f\n",s[i].total);
            return;
        }
    }
    printf("not found\n");
}

void find_student(const Student s[],int n)
{
    int mode;
    char key[MAX_NAME_LEN];
    scanf("%d",&mode);
    scanf("%s",key);
    for(int i=0;i<n;i++)
    {
        if((mode==1&&strcmp(s[i].id,key)==0)||
           (mode==2&&strcmp(s[i].name,key)==0))
        {
            print_student(&s[i]);
            return;
        }
    }
    printf("not found\n");
}

void swap_student(Student *a,Student *b)
{
    Student t=*a;
    *a=*b;
    *b=t;
}

void sort_by_total(Student s[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(s[j].total<s[j+1].total)
                swap_student(&s[j],&s[j+1]);
        }
    }
}

void sort_by_some_courses(Student s[],int n)
{
    int k;
    int idx[COURSE_COUNT];
    scanf("%d",&k);
    if(k<1||k>COURSE_COUNT)
    {
        printf("invalid k\n");
        return;
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d",&idx[i]);
        if(idx[i]<1||idx[i]>COURSE_COUNT)
        {
            printf("invalid course\n");
            return;
        }
        idx[i]--; 
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            float sumj=0.0f,sumj1=0.0f;
            for(int t=0;t<k;t++)
            {
                sumj+=s[j].score[idx[t]];
                sumj1+=s[j+1].score[idx[t]];
            }
            if(sumj<sumj1) swap_student(&s[j],&s[j+1]);
        }
    }
}

int main()
{
    Student s[MAX_STUDENTS];
    int n=0;
    int op;
    while(1)
    {
        if(scanf("%d",&op)!=1) break;
        if(op==0) break;
        if(op==1) input_students(s,&n);
        else if(op==2) average_of_course(s,n);
        else if(op==3) total_of_one(s,n);
        else if(op==4) find_student(s,n);
        else if(op==5)
        {
            sort_by_some_courses(s,n);
            for(int i=0;i<n;i++) print_student(&s[i]);
        }
        else if(op==6)
        {
            sort_by_total(s,n);
            for(int i=0;i<n;i++) print_student(&s[i]);
        }
    }
    return 0;
}

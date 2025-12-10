#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_OF_ALL 50

struct Student
{
    char name[MAX_NUM_OF_ALL];
    float score[MAX_NUM_OF_ALL];
    float total;
};
typedef struct Student Student;
void Input_StudentInfo(Student s[],int n,const int CourseNum)
{
    for(int i=0;i<n;i++)
    {
        s[i].total=0.0f;
        scanf("%s",s[i].name);
        for(int j=0;j<CourseNum;++j)
        {
            scanf("%f",&s[i].score[j]);
            s[i].total+=s[i].score[j];
        }
    }

}

void Query_CourseInfo(const Student s[],const int n,const int CourseNum)
{
    int c;
    c=0;

    printf("Chinese\n");
    float sum=0.0f;
    for(int i=0;i<n;i++)sum+=s[i].score[c];
    printf("sum=%.2f avg=%.2f\n",sum,sum/n);

    printf("******************************\n");

    c=1;
    printf("Math\n");
    sum=0.0f;
    for(int i=0;i<n;i++)sum+=s[i].score[c];
    printf("sum=%.2f avg=%.2f\n",sum,sum/n);
}


int main()
{
    Student s[MAX_NUM_OF_ALL];
    int n;
    int CourseNum;
    n=3;
    CourseNum=2;
    Input_StudentInfo(s,n,CourseNum);
    
    Query_CourseInfo(s, n,CourseNum);
    return 0;
}

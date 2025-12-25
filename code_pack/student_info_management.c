#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM_OF_ALL 50
//once-and-for-all
struct Student
{
    char id[MAX_NUM_OF_ALL];
    char name[MAX_NUM_OF_ALL];
    float score[MAX_NUM_OF_ALL];
    float total;
};
typedef struct Student Student;
void Input_StudentInfo(Student s[],int *pn,const int CourseNum)
{
    int n;
    printf("? new students");
    scanf("%d",&n);
    printf("\n");
    for(int i=(*pn);i<n+(*pn);i++)
    {
        s[i].total=0.0f;
        scanf("%s",s[i].id);
        scanf("%s",s[i].name);
        for(int j=0;j<CourseNum;++j)
        {
            scanf("%f",&s[i].score[j]);
            s[i].total+=s[i].score[j];
        }
    }
    //传入指针 进行更改

    (*pn)+=n;
}

void print(const Student *p,const int CourseNum)
{
    printf("---------------------------------------------------\n");
    printf("%s - %s :",p->id,p->name);
    for(int j=0;j<CourseNum;j++) printf("\t %.2f",p->score[j]);
    printf("         %.2f\n",p->total);
    printf("---------------------------------------------------\n");
}

void Query_CourseInfo(const Student s[],const int n,const int CourseNum)
{
    int c;
    printf("Course ?\n");
    scanf("%d",&c);
    float sum=0.0f;
    for(int i=0;i<n;i++)sum+=s[i].score[c];
    printf("sum=%.2f avg=%.2f\n",sum,sum/n);
}

void Query_StudentInfo(const Student s[],const int n,const int CourseNum)
{
   printf("The kth input?\n");
   int k;scanf("%d",&k);
   --k;
    print(&s[k],CourseNum);
        
   
}

void Find_Student(const Student s[],int n,int CourseNum)
{

    int mode;
    char key[MAX_NUM_OF_ALL];
     printf("Name or ID ?\n");
    scanf("%d",&mode);
    printf("So :");
    scanf("%s",key);
//查学号or查姓名
    for(int i=0;i<n;i++)
    {
        if((mode==2&&strcmp(s[i].id,key)==0)||
           (mode==1&&strcmp(s[i].name,key)==0))
        {
            //字符串比较函数
            print(&s[i], CourseNum);
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



void Print_StudentInfo(const Student s[],int n,int CourseNum)
{
    printf("**************************************\n");
    for(int i=0;i<n;i++)print(&s[i],CourseNum);
    printf("**************************************\n");
}

void Maintain_StudentInfo(Student s[],int n)
{
//如果要按照所有学科排名的话，就手动输入所有学科叭
    int k;
    int CourseId[MAX_NUM_OF_ALL];
    printf("How many courses? Which?\n");
    scanf("%d",&k);
  
    for(int i=0;i<k;i++)
    {
        scanf("%d",&CourseId[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            float sumStudentI=0.0f,sumStudentJ=0.0f;
              //暴力查看交换条件
            for(int t=0;t<k;t++)
            {
                sumStudentI+=s[j].score[CourseId[t]];
           
                sumStudentJ+=s[j+1].score[CourseId[t]];
            }
            if(sumStudentI<sumStudentJ)swap_student(&s[j],&s[j+1]);
        }
    }
}

int main()
{
    Student s[MAX_NUM_OF_ALL];
    int n=0;
    int CourseNum;
    int op;
    scanf("%d",&CourseNum);
    while(1)
    {
        printf("\n-------------------------------\nOP :");
        scanf("%d",&op);
        switch(op)
        {
            case 0:
                return 0;
            case 1:
                Input_StudentInfo(s,&n,CourseNum);
                break;
            case 2:
                Query_CourseInfo(s, n,CourseNum);
                break;
            case 3:
                Query_StudentInfo(s,n,CourseNum);
                break;
            case 4:
                Find_Student(s,n,CourseNum);
                break;
            case 5:
                Maintain_StudentInfo(s,n);
                Print_StudentInfo(s,n,CourseNum);
                break;
            case 6:
                Print_StudentInfo(s,n,CourseNum);
                break;
            default:
                break;//只是退出switch
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int id;
    char name[100];
    float score;
    struct Student *nxt;
 
};
typedef struct Student Student;
void append(Student* pStart,Student* pEnd,const Student newstudent)
{
    Student* ptr;
    ptr=pStart;
    while(ptr->nxt!=pEnd)ptr=ptr->nxt;
    (ptr->nxt)=(Student*)malloc(sizeof(Student));
    *(ptr->nxt)=newstudent;
    (ptr->nxt->nxt)=pEnd;
    printf("Successfully Append;\n");
}
void print(Student* pStart,Student* pEnd)
{
    printf("**********\n");
    Student* ptr;
    ptr=pStart;
    while(ptr->nxt!=pEnd)
    {
        ptr=ptr->nxt;//先跳了再说
        printf("%d %s %.2f\n",ptr->id,ptr->name,ptr->score);
    }
    printf("**********\n");
}
void del(Student* pStart,Student* pEnd,int oldid)
{
    Student* ptr;
    ptr=pStart;
    while(ptr->nxt!=pEnd)
    {
        if((ptr->nxt)->id==oldid)
        {
            ptr->nxt=(ptr->nxt)->nxt;
            printf("Successfully Delete;\n");
            return;
        }
        ptr=ptr->nxt;
    }
}
int main()
{
    Student Start,End;//两个虚拟的空头空尾
    Start.nxt=&End;
    End.nxt=NULL;

    int n;
    int op;
    while(1)
    { printf("######################\n op:? \n");
        scanf("%d",&op);
        printf("\n");
        switch(op)
        {
           
            case 1:
            {
                printf("Input id, name, score:\n");
                Student newstudent;
                scanf("%d %s %f",&newstudent.id,newstudent.name,&newstudent.score);
                append(&Start,&End,newstudent);
                break;
            }
            case 2:
            {
               print(&Start,&End);
               break;
            }
            case 3:
            {
                printf("Input id\n");
                int oldid;
                scanf("%d",&oldid);
                del(&Start,&End,oldid);
                break;
            }
            default:
                return 0;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    int id;
    struct ListNode* prev;
    struct ListNode* next;
};
typedef struct ListNode ListNode;
ListNode* new_node(int v,int id)
{
    ListNode* p=(ListNode*)malloc(sizeof(ListNode));
    if (!p)return NULL;
    //初始化
    p->val=v;
    p->id=id;
    p->prev = p->next = NULL;
    return p;
}
void init(ListNode* head,ListNode* tail)
{
    head->prev=NULL;
    tail->next=NULL;

    head->next=tail;
    tail->prev=head;
}
void append(ListNode* tail, ListNode* node) {
    ListNode *front=(tail->prev);
    front->next=node;
    node->prev=front;
    node->next=tail;
    tail->prev=node;
}



void copyList(ListNode *head, ListNode *tail, ListNode *newhead, ListNode *newtail)
{
    ListNode *p=head->next;

    while(p!=tail)
    {
        ListNode *node=new_node(p->val,p->id);
        append(newtail,node);
        p=p->next;
    }
}
void copyReversedList(ListNode *head, ListNode *tail, ListNode *newhead, ListNode *newtail)
{
    ListNode *p=tail->prev;

    while(p!=head)
    {
        ListNode *node=new_node(p->val,p->id);
        append(newtail,node);
        p=p->prev;
    }
}
void print_list(ListNode* head,ListNode* tail)
{
    ListNode *p = head->next;
    printf("----------------\n");
    while(p!=tail)
    {
  //      printf("%d , %d    ",p->val,p->id);
  printf("%d ", p->val);
        p=p->next;
    }
    printf("\n");
    printf("----------------\n");
}

void copySorted(struct ListNode* head,  ListNode* tail, ListNode* newhead, ListNode* newtail,int n)
{
    ListNode *p;
    ListNode *cur=NULL;
    
   
    
    ListNode *min_node;
    while(n--)
    {
        // printf("test line 71 while\n");
        // print_list(head,tail);
        // print_list(newhead,newtail);
        min_node=new_node(10000,1000);
        // //min_node是一个指针！
        //每轮都要新开！
        //这是  分配内存的关键！！
        for(p=head->next;p!=tail;p=p->next)
        {
            if((p->id)<0)continue;
            if(p->val<min_node->val)
            {
 //               printf("%d!!!!\n",n);
                *min_node=*p;
            }
        }
        for(p=head->next;p!=tail;p=p->next)
        {
            if((*p).val==(*min_node).val)
            {
                (p->id)*=-1;
                append(newtail,min_node);
    //            printf("Line105:%d \n",newhead->next->val);
                break;
            }
        }
    }
    for(p=head->next;p!=tail;p=p->next)
    {
        p->id*=-1;
    }
}
int main(void) {
    int Input_arr[] = {1, 3, 2, 4, 5, 6};
    int n = sizeof(Input_arr) / sizeof(Input_arr[0]);
    ListNode Head,Tail;
    ListNode Head1,Tail1;
    ListNode Head2,Tail2;
    ListNode Head3,Tail3;
    int i;
    init(&Head,&Tail);
    init(&Head1,&Tail1);
    init(&Head2,&Tail2);
    init(&Head3,&Tail3);
    
    for(i=0;i<n;++i)
    {
        ListNode * node=new_node(Input_arr[i],i+1);
        append(&Tail,node);
    }
    copyList(&Head,&Tail,&Head1,&Tail1);
    copyReversedList(&Head,&Tail,&Head2,&Tail2);
    copySorted(&Head,&Tail,&Head3,&Tail3,n);
    print_list(&Head1,&Tail1);
    print_list(&Head2,&Tail2);
    print_list(&Head3,&Tail3);
    

    return 0;
}

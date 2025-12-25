#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b)) 
#define min(a,b) ((a)<(b)?(a):(b))
struct Node
{
    int val;
    struct Node *nxt;
};
typedef struct Node Node;
Node *create_Node(int val)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->val=val;
    newNode->nxt=NULL;
    return newNode;
}
void append(Node *head,int val)
{
    Node *newNode=create_Node(val);
    Node *tail;
    tail=head;
    while(tail->nxt!=NULL)
    {
        tail=tail->nxt;
    }
    tail->nxt=newNode;
    newNode->nxt=NULL;
  
}
void delte_mn(Node *head)
{
    Node *tail;
    Node *prev;
    int mn;
    tail=head;
    mn=1000;
    while(tail->nxt!=NULL)
    {
        tail=tail->nxt;
        mn=min(mn,tail->val);
    }
    tail=head;
    prev=head;
    while(tail->nxt!=NULL)
    {
        tail=tail->nxt;
        if(tail->val==mn)
        {
            prev->nxt=tail->nxt;
            free(tail);
           return;
        }
        prev=tail;
    }
}
void delte_mx(Node *head)
{
    Node *tail;
    Node *prev;
    int mx;
    tail=head;
    mx=-1000;
    while(tail->nxt!=NULL)
    {
        tail=tail->nxt;
        mx=max(mx,tail->val);
    }
    tail=head;
    prev=head;
    while(tail->nxt!=NULL)
    {
        tail=tail->nxt;
        if(tail->val==mx)
        {
            prev->nxt=tail->nxt;
            free(tail);
           return;
        }
        prev=tail;
    }
}
void print_list(Node *head)
{
    Node *tail;
    tail=head;
    printf("##################\n");
    while(tail->nxt!=NULL)
    { tail=tail->nxt;
        printf("%d \t",tail->val);
       
    }

}
int main()
{
    Node Head;
    int n;int val;

    Head.nxt=NULL;
    Head.val=404;
    //无意义的表头
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&val);
        append(&Head,val);
    }
    delte_mn(&Head);
    delte_mx(&Head);
    print_list(&Head);
    return 0;
}
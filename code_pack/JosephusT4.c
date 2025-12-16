#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int id;
    struct ListNode* prv;
    struct ListNode* nxt;
};
typedef struct ListNode ListNode;
ListNode* new_node(int id)
{
    ListNode* p=(ListNode*)malloc(sizeof(ListNode));
    if (!p)return NULL;
    //初始化
 
    p->id=id;
    p->prv=p->nxt=NULL;
    return p;
}

// create circular list of n nodes labeled 1..n, returns head (1)
ListNode* create_circle(int n)
{
    ListNode* entry=new_node(1);
    ListNode* last;
    ListNode* p;
    int i;
    if(n==1)
    {
        
        return entry;
    }
    last=entry;
    for(i=2;i<n;++i)
    {
        p=new_node(i);
        last->nxt=p;
        p->prv=last;
        last=p;
    }
     p=new_node(n);
    last->nxt=p;
    p->prv=last;

    p->nxt=entry;
    entry->prv=p;
    return entry;
}


void josephus(int n, int m)
{
    int i,cnt;
    ListNode* temp;
    ListNode* entry=create_circle(n);
    for(i=1;i<=n;++i)
    {
        cnt=0;
        while(cnt<m-1)
        {
            ++cnt;
            entry=entry->nxt;
        }
        printf("%d ",entry->id);
        temp=entry;
        entry=entry->nxt;
        temp->prv->nxt=entry;
        entry->prv=temp->prv;
        free(temp);
    
    }
    printf("\n");
}

int main(void) {
   
    josephus(5, 3); //  3,1,5,2,4

    
    josephus(10, 4); //
/*
 4, 8, 2, 7, 3, 10, 9, 1, 6, 5
*/
    return 0;
}

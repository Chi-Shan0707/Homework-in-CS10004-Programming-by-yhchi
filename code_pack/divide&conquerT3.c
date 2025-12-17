#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
struct Node
{
    int val;
    struct Node *pre;
    struct Node *nxt;
};
typedef  struct Node Node;

void printList(Node* head,Node *tail)
{
    Node* p = head;
    printf("*********************************\n");
    while(p!=tail)
    {
        printf("%d,", p->val);
        p = p->nxt;
    }

    printf("%d\n",tail->val);
}
void array_to_list(Node *head,Node *tail,int* arr, int n)
{
    Node *last,*cur;
    int i;

    head->nxt=tail;
    tail->pre=head;

    head->pre=NULL;
    tail->nxt=NULL;

    last=head;
    for(i=0;i<n;++i)
    {
        cur=(Node*)malloc(sizeof(Node));
        //
        cur->val=arr[i];
        cur->nxt=NULL;
        cur->pre=last;

        //更新
        last->nxt=cur;
        last=cur;
    }
    last->nxt = tail;
    tail->pre=last;
}
/*
有必要分治嘛
*/
Node * merge(Node *head1,Node *tail1,Node *head2,Node *tail2,int key)
{
  
    Node *cur1 = NULL; Node *cur2 =NULL; 
    Node *cur3 = NULL; Node *cur4 =NULL; 
     Node *p, *next;

    // 遍历第一段 [head1..tail1]
    p = head1;
    while (1) {
        next = p->nxt;
        p->nxt = p->pre = NULL;
        if (p->val < key) {
            if (!cur1) cur1 = cur2 = p;
            else { cur2->nxt = p; p->pre = cur2; cur2 = p; }
        } else {
            if (!cur3) cur3 = cur4 = p;
            else { cur4->nxt = p; p->pre = cur4; cur4 = p; }
        }
        if (p == tail1) break;
        p = next;
    }

    // 遍历第二段 [head2..tail2]
    p = head2;
    while (1) {
        next = p->nxt;
        p->nxt = p->pre = NULL;
        if (p->val < key) {
            if (!cur1) cur1 = cur2 = p;
            else { cur2->nxt = p; p->pre = cur2; cur2 = p; }
        } else {
            if (!cur3) cur3 = cur4 = p;
            else { cur4->nxt = p; p->pre = cur4; cur4 = p; }
        }
        if (p == tail2) break;
        p = next;
    }

    // 拼接
    if (!cur1) {
        if (cur4) cur4->nxt = NULL;
        return cur3;
    }
    cur2->nxt = cur3;
    if (cur3) cur3->pre = cur2;
    if (cur4) cur4->nxt = NULL;
    return cur1;
    


}
Node* solve(Node *head,Node *tail,int len,int key)
{
    
    Node *cur1 = NULL; 
    Node *cur2 = NULL; 
    Node *cur3 = NULL; 
    Node *cur4 = NULL; 
    Node *p = head;
    Node *next;
    if (len <= 0 ) return head;
    if(head==NULL)return head;
    while (1) {
        next = p->nxt;
        p->nxt = p->pre = NULL;
        if(p->val<key) 
        {
            if(!cur1)cur1=cur2=p;
            else 
            { 
                cur2->nxt=p; 
                p->pre=cur2; 
                cur2=p;
            }
        } 
        else 
        {
            if (!cur3) cur3 = cur4 = p;
            else 
            { 
                cur4->nxt = p;
                p->pre =cur4;
                cur4 = p;
            }
        }
        if(p==tail)break;
        p=next;
    }
    if(!cur1) 
    {
        if (cur4)cur4->nxt=NULL;
        return cur3;
    }
    cur2->nxt=cur3;
    if(cur3)cur3->pre=cur2;
    if(cur4)cur4->nxt=NULL;
    return cur1;
}
int main()
{
    int arr[10],n,key;
    Node Head,Tail;
    /*
    ：输入：链表节点数n=6，链表中的值1, 4, 3, 2, 5, 2，分割值x=3；输出：1, 2, 2, 4, 3, 5。

                            输入：链表节点数n=5，链表中的值2, 1, 2, 2, 1，分割值x=2；输出：1, 1, 2, 2, 2。
    */
    arr[0]=1,arr[1]=4,arr[2]=3,arr[3]=2,arr[4]=5,arr[5]=2;
    n=6;
    key=3;
    array_to_list(&Head,&Tail,arr,n);

    printList(Head.nxt,Tail.pre);

 
    Node *new_head = solve(Head.nxt, Tail.pre, n, key);
    Head.nxt = new_head;
   
    Node *t = Head.nxt;
    if(t)
    {
        while (t->nxt)t=t->nxt;
        t->nxt=&Tail;
        Tail.pre = t;
    } 
    else 
    {
        Head.nxt = &Tail;
        Tail.pre = &Head;
    }
    printList(Head.nxt,Tail.pre);


    arr[0]=2,arr[1]=1,arr[2]=2,arr[3]=2,arr[4]=1;
    n=5;
    return 0;
}
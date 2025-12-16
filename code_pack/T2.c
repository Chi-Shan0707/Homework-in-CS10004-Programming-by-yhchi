#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    int id;
    struct ListNode* input_nxt;
    struct ListNode* input_pre;
    struct ListNode* order_nxt;
    struct ListNode* order_pre;
};
typedef struct ListNode ListNode;
ListNode* new_node(int v,int id)
{
    ListNode* p=(ListNode*)malloc(sizeof(ListNode));
    if (!p)return NULL;
    //初始化
    p->val=v;
    p->id=id;
    p->input_nxt=NULL;
    p->order_nxt=NULL;
    return p;
}

void append(ListNode* tail, ListNode* node) {
    ListNode *front=(tail->input_pre);

    front->input_nxt=node;
    node->input_pre=front;

    node->input_nxt=tail;
    tail->input_pre=node;
}

int main(void)
{
    int in_arr[] = {1, 3, 2, 4, 5, 6};
    int n = sizeof(in_arr) / sizeof(in_arr[0]);
    ListNode Input_Head,Order_Head;
    ListNode Input_Tail,Order_Tail;
    Input_Head.input_nxt=&Input_Tail;
    Input_Tail.input_pre=&Input_Head;
    Order_Head.order_nxt=&Order_Tail;
    Order_Tail.order_pre=&Order_Head;
    for(int i=0;i<n;++i)
    {
        ListNode *newnode=new_node(in_arr[i],i);
        append(&Input_Tail,newnode);
    }
    for(int i=0;i<n;++i)
    {
        ListNode *p;
        int min=100;
        for(p=Input_Head.input_nxt;p!=&Input_Tail;p=p->input_nxt)
        {
            if(p->val>0&&p->val<min)
            {
                min=p->val;
            }
        }
        for(p=Input_Head.input_nxt;p!=&Input_Tail;p=p->input_nxt)
        {
            if(p->val==min)
            {
                ListNode *front=(Order_Tail.order_pre);

                front->order_nxt=p;
                p->order_pre=front;
                p->order_nxt=&Order_Tail;
                Order_Tail.order_pre=p;

                p->val*=-1;

                break;
            }
        }

    }
    for(ListNode* p=Order_Head.order_nxt;p!=&Order_Tail;p=p->order_nxt)
    {
        p->val*=-1;
        printf("val:%d  id:%d\n",p->val, p->id);
    }
    return 0;
}
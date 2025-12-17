#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};

// 打印链表
typedef struct Node Node;
void printList(Node* head)
{
    Node* p = head;
    printf("*********************************\n");
    while(p!=NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
Node* mergeSortedLists(Node* head1, Node* head2)
{
    Node *head;
    Node *tail;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    //竟然莫名的像fhq_treap
    if(head1->val<head2->val)
    {
    
        head1->next=mergeSortedLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next=mergeSortedLists(head1, head2->next);
        return head2;   
    }
    //这里也像fhq_treap的merge

}

Node* array_to_list(int* arr, int n)
{
   
    int i;
    Node* head = (Node*)malloc(sizeof(Node));
    Node* tail;
    Node* cur;
    if(n==0)return head=NULL;
    head->val=arr[0];
    head->next=NULL;
    tail=head;
    for(i=1;i<n;++i)
    {
        cur=(Node*)malloc(sizeof(Node));
        cur->val=arr[i];
        cur->next=NULL;
        tail->next=cur;
        tail=cur;
        
    }
    return head;
}

//程序终止自会销毁，这里额外显式销毁
void freeList(Node* head)
{
    while(head)
    {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    int arr1[]={1,3,5};
    int arr2[]={2,4,6};
    Node* list1=array_to_list(arr1, 3);
    printList(list1);
    Node* list2=array_to_list(arr2, 3);
    printList(list2);
    Node* merged = mergeSortedLists(list1, list2);

    
    printList(merged);
    freeList(merged);
    return 0;
}

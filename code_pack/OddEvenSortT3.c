#include <stdio.h>
#include <stdlib.h>

// 单向链表节点
struct Node
{
    int val;
    struct Node* next;
};

typedef struct Node Node;

// 表头结构
struct List
{
    Node* lsthead; // 注意：不使用辅助表元（无哨兵）
};

typedef struct List List;

// 从数组创建链表（数组应为已排序且不含重复元素以表示集合）
void convert(List* lst, int arr[], int n)
{
    lst->lsthead = NULL;
    if (n <= 0) return;
    Node *head = ( Node *) malloc ( sizeof (Node) ) ;
    head->val = arr[0];
    head->next = NULL;
    lst->lsthead = head;
    Node* tail = head;
    for (int i = 1; i < n; ++i) 
    {
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->val = arr[i];
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
    }
}

void free_list(List* lst) 
{
    Node* head = lst->lsthead;
    while(head)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    lst->lsthead = NULL;
    //记得置空
}

void print_list(const char* name, List* lst)
{
    printf(" List %s  =    {    ", name);
    Node* head = lst->lsthead;
    int is_firstitem = 1;
    while (head)
    {
        if (!is_firstitem) printf(" -> ");
        printf("%d", head->val);
        is_firstitem = 0;
        head = head -> next;
    }
    printf("    }\n");
}

void append(List *lst, Node **tail_ptr,int val)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
    if (lst->lsthead == NULL)
    {
        lst->lsthead=new_node;
    } 
    else 
    {
        (*tail_ptr)->next=new_node;
    }
    *tail_ptr = new_node;
}
void operate(List *lst,int n)
{
    Node *head = lst->lsthead;
    Node *tail = head;
    Node *cur;
    Node *temp;
    Node *second;
    int m = n >> 1;
    int i = 0;
    if(n<=2)return;
    second=head->next;
    if ( n & 1 )
    {
        for( i = 0; i< m-1;++i)
        {
            cur =tail;
            tail=tail->next;
            tail=tail->next;
            (cur->next)->next=tail->next;
            cur->next=tail;
        }
       
        //剩仨
        cur=tail;
        tail=tail->next;
        tail=tail->next;
        tail->next=second;//原正数第二个
        second=cur->next;//原倒数第二个
        cur->next=tail;//倒数第三个接到最后一个
         
        //整条奇链的尾巴
        second->next=NULL;
        //重新配置空结点

//        printf("%d  %d %d",cur->val,cur->next->val,cur->next->next->val);
        
    }
    else
    {
        for( i = 0; i< m-1;++i)
        {
            cur =tail;
            tail=tail->next;
            tail=tail->next;
            (cur->next)->next=tail->next;
            cur->next=tail;
        }
        //剩俩
        cur=tail;
        tail=tail->next;
        cur->next=second;//接入正数第二个
        tail->next=NULL;//尾巴变
    }
}

int main() {
    List lst1,lst2,lst3;
    /*
    给定一个带头结点的单链表，将链表重新排序，使所有奇数位置的节点排在偶数位置节点之前。要求保持节点的相对顺序不变。位置编号从1开始，1为奇数位，2为偶数位，以此类推。测试要求：1). 1->2->3->4->5->NULL (预计输出：1->3->5->2->4->NULL); 2). 2->8->3->7->NULL (预计输出：  )
    */
    int arr1[] = { 1 , 2, 3, 4, 5 };
    int arr2[] = { 1 , 3, 5, 2, 4 };
    int arr3[] = { 2 , 8, 3, 7 };
    convert(&lst1, arr1, sizeof(arr1)/sizeof(arr1[0]));
    convert(&lst2, arr2, sizeof(arr2)/sizeof(arr2[0]));
    convert(&lst3, arr3, sizeof(arr3)/sizeof(arr3[0]));
    operate(&lst1, sizeof(arr1)/sizeof(arr1[0]));
    operate(&lst2, sizeof(arr2)/sizeof(arr2[0]));   
    operate(&lst3, sizeof(arr3)/sizeof(arr3[0]));
    print_list("After operation, List 1", &lst1);
    print_list("After operation, List 2", &lst2);
    print_list("After operation, List 3", &lst3);
    free_list(&lst1);
    free_list(&lst2);
    free_list(&lst3);
    return 0;
}

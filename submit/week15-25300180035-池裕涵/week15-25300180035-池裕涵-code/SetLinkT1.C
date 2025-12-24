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
    printf("set %s  =    {", name);
    Node* head = lst->lsthead;
    int is_firstitem = 1;
    while (head)
    {
        if (!is_firstitem) printf(" , ");
        printf("%d", head->val);
        is_firstitem = 0;
        head = head -> next;
    }
    printf("}\n");
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
// 2. 差集 S1 \ S2
void differenceSet(struct List *s1, struct List *s2, struct List *res) {
    
    Node* head1 = s1->lsthead;
    Node* head2 = s2->lsthead;
    Node* tail = NULL;
    free_list(res);
    res->lsthead = NULL;
    while(head1!=NULL)
    {
        int exist_in_s2=0;
        for(head2=s2->lsthead; head2!=NULL; head2=head2->next)
        {
            if(head2->val==head1->val)
            {
                exist_in_s2=1;
                break;
            }
        }
        if(!exist_in_s2)append(res, &tail, head1->val);
        head1=head1->next;
    }
    
}
void intersectionSet(struct List *s1, struct List *s2, struct List *res)
{
    Node* head1 = s1->lsthead;
    Node* head2 = s2->lsthead;
    Node* tail = NULL;
    free_list(res);
    res->lsthead = NULL;
    while(head1!=NULL)
    {
        int exist_in_both=0;
        for(head2=s2->lsthead; head2!=NULL; head2=head2->next)
        {
            if(head2->val==head1->val)
            {
                exist_in_both=1;
                break;
            }
        }
        if(exist_in_both)append(res, &tail, head1->val);
        head1=head1->next;
    }
}

void unionSet(struct List *s1, struct List *s2, struct List *res) 
{
    Node* head1 = s1->lsthead;
    Node* head2 = s2->lsthead;
    Node* tail = NULL;
    free_list(res);
    res->lsthead = NULL;
    head2=s2->lsthead;
    while(head2!=NULL)
    {
        append(res, &tail, head2->val);
        head2=head2->next;
    }
    head2=s2->lsthead;

    while(head1!=NULL)
    {
        int exist_in_s2=0;
        for(head2=s2->lsthead; head2!=NULL; head2=head2->next)
        {
            if(head2->val==head1->val)
            {
                exist_in_s2=1;
                break;
            }
        }
        if(!exist_in_s2)append(res, &tail, head1->val);
        head1=head1->next;
    }
    
}

int main() {
    List S1, S2, U, D, I;
    int a1[] = {2, 3, 5, 6};
    int a2[] = {3, 4, 6, 8};
    convert(&S1, a1, sizeof(a1)/sizeof(a1[0]));
    convert(&S2, a2, sizeof(a2)/sizeof(a2[0]));
    U.lsthead = D.lsthead = I.lsthead = NULL;

    print_list("S1", &S1);
    print_list("S2", &S2);

    unionSet(&S1, &S2, &U);
    print_list("S1∪S2", &U);

    differenceSet(&S1, &S2, &D);
    print_list("S1\\S2", &D);

    intersectionSet(&S1, &S2, &I);
    print_list("S1∩S2", &I);

    // 释放
    free_list(&S1);
    free_list(&S2);
    free_list(&U);
    free_list(&D);
    free_list(&I);
    return 0;
}

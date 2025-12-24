#include <stdio.h>
#include <stdlib.h>
struct Node
 {
    int val;
    struct Node* next;
};
typedef struct Node Node;
Node* convert(int arr[], int n) 
{
    int i;
    Node* head = (Node*)malloc(sizeof(Node));
    Node   *tail=head;
    if(n == 0)return NULL;
    head->val = arr[0];
    head->next = NULL;
    for(i=1;i<n;++i)
    {
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->val = arr[i];
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
    }
    return head;
}
void print_list(const char* name, Node* head)
{
    printf(" List %s  =    {    ", name);
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
void free_list(Node* head) {
    while (head)
    {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}
// Delete: 删除值大于 min 且小于 max 的结点，同时释放空间
void Delete(Node** head_ptr, int min, int max) {
    if (head_ptr == NULL) return;
    Node* cur = *head_ptr;
    Node* prev = NULL;
    while (cur) {
        if (cur->val > min && cur->val < max) {
            Node* to_del=cur;
            if (prev == NULL) {
                // 删除头结点,比较麻烦
                *head_ptr=cur->next;//将问题留给下一个人
                cur = *head_ptr;
            } 
            else 
            {
                prev->next=cur->next;
                cur = prev->next;
            }
            free(to_del);
        }
         else
         {
            prev=cur;
            cur=cur->next;
        }
    }
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    Node* head = convert(arr, sizeof(arr)/sizeof(arr[0]));

    
/*
 创建链表，链表中的结点值依次为“10 20 30 40 50”，Delete 函数用于删除链表中所有值大于 min 且小于 max 的结点(表元)，同时释放被删结点空间。如设定 min=10 和 max=35，Delete 函数将使得链表中结点值被删为"10 40 50“。
*/
    int min = 10, max = 35;
    print_list("Before operation(min=10, max=35)", head);
    Delete(&head, min, max);

    print_list("After operation(min=10, max=35)", head);

    free_list(head);
    return 0;
}

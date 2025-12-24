#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int count;
    struct Node* next;
};
typedef struct Node Node;

Node* new_node(int v)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (!p) return NULL;
    p->val = v;
    p->count = 1;
    p->next = NULL;
    return p;
}

void insert(Node** head, int v)
{
    Node* newn = new_node(v);
    Node* cur = *head;
    if (*head == NULL) 
    {
        *head = newn;
        return;
    }
    if ((*head)->val > v) 
    {
        newn->next = *head;
        *head = newn;
        return;
    }
   
    while (cur ->next != NULL && cur ->next->val< v) 
    // 不断向后找，知道找到合适的位置
    {
        cur = cur ->next;
    }
    //插入排序√
    if (cur->next != NULL && cur ->next->val == v) {
        cur->next->count++;
        free(newn);
        return;
    }
    newn->next = cur->next;
    cur->next = newn;
}

void write_list(Node* head)
{
    Node* p = head;
    while (p != NULL) 
    {
        printf("%d %d\n", p->val, p->count);
        p = p->next;
    }
}
void free_list(Node* head)
{
    Node* tail = head;
    while (head != NULL) 
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
int main(void)
{
    char filename[100];Node* head = NULL;int num;
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if(!fp) 
    {
        printf("404 NOT FOUND\n");
        return 1;
    }
    
    
    while(fscanf(fp, " %d", &num) == 1)
    {
        insert(&head, num);
    }
    fclose(fp);
    write_list(head);
    free_list(head);
    return 0;
}
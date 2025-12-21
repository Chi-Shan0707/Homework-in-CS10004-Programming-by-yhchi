#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// 从数组创建链表
Node* list_from_array(int arr[], int n) {
    if (n <= 0) return NULL;
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->data = arr[i];
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
    }
    return head;
}

// 打印链表
void print_list(const char* msg, Node* head) {
    printf("%s: ", msg);
    Node* p = head;
    if (!p) { printf("(empty)\n"); return; }
    int first = 1;
    while (p) {
        if (!first) printf(" ");
        printf("%d", p->data);
        first = 0;
        p = p->next;
    }
    printf("\n");
}

// 释放链表
void free_list(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Delete: 删除值大于 min 且小于 max 的结点，同时释放空间
void Delete(Node** head_ref, int min, int max) {
    if (head_ref == NULL) return;
    Node* curr = *head_ref;
    Node* prev = NULL;
    while (curr) {
        if (curr->data > min && curr->data < max) {
            Node* to_del = curr;
            if (prev == NULL) {
                // 删除头结点
                *head_ref = curr->next;
                curr = *head_ref;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }
            free(to_del);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    Node* head = list_from_array(arr, sizeof(arr)/sizeof(arr[0]));

    print_list("原链表", head);

    int min = 10, max = 35;
    Delete(&head, min, max);

    print_list("删除后 (min=10, max=35)", head);

    free_list(head);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 单向链表节点
typedef struct Node {
    int val;
    struct Node *nxt;
} Node;

// 将原链表就地分割：所有 < x 的节点在前，>= x 的节点在后，保持相对顺序，不创建新节点
Node* partition_inplace(Node* head, int x) {
    Node *less_head = NULL, *less_tail = NULL;
    Node *ge_head = NULL, *ge_tail = NULL;
    Node *cur = head;
    while (cur) {
        Node *next = cur->nxt;
        cur->nxt = NULL; // 断开，安全地移动节点
        if (cur->val < x) {
            if (!less_head) less_head = less_tail = cur;
            else { less_tail->nxt = cur; less_tail = cur; }
        } else {
            if (!ge_head) ge_head = ge_tail = cur;
            else { ge_tail->nxt = cur; ge_tail = cur; }
        }
        cur = next;
    }
    if (!less_head) return ge_head;
    less_tail->nxt = ge_head;
    return less_head;
}

// 辅助：从数组创建链表（为测试而建，创建节点仅用于初始构造，分割过程不创建新节点）
Node* build_list_from_array(int *a, int n) {
    if (n <= 0) return NULL;
    Node *head = (Node*)malloc(sizeof(Node));
    head->val = a[0]; head->nxt = NULL;
    Node *tail = head;
    for (int i = 1; i < n; ++i) {
        Node *p = (Node*)malloc(sizeof(Node));
        p->val = a[i]; p->nxt = NULL;
        tail->nxt = p; tail = p;
    }
    return head;
}

void print_list(Node *head) {
    Node *p = head;
    int first = 1;
    while (p) {
        if (!first) printf(", ");
        printf("%d", p->val);
        first = 0;
        p = p->nxt;
    }
    printf("\n");
}

void free_list(Node *head) {
    while (head) {
        Node *t = head->nxt;
        free(head);
        head = t;
    }
}

int main(void) {
    // 程序从 stdin 读取：
    // 第一行：n
    // 第二行：n 个整数（或同一行）
    // 第三行：x
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *a = (int*)malloc(sizeof(int) * (n>0?n:0));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int x; scanf("%d", &x);

    Node *head = build_list_from_array(a, n);
    free(a);

    head = partition_inplace(head, x);
    print_list(head);

    free_list(head);
    return 0;
}

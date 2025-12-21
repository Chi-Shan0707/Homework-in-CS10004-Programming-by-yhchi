#include <stdio.h>
#include <stdlib.h>

// 单向链表节点
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// 表头结构
struct List {
    Node* head; // 注意：不使用辅助表元（无哨兵）
};

typedef struct List List;

// 从数组创建链表（数组应为已排序且不含重复元素以表示集合）
void list_from_array(List* lst, int arr[], int n) {
    lst->head = NULL;
    if (n <= 0) return;
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;
    lst->head = head;
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->data = arr[i];
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
    }
}

void free_list(List* lst) {
    Node* p = lst->head;
    while (p) {
        Node* tmp = p;
        p = p->next;
        free(tmp);
    }
    lst->head = NULL;
}

void print_list(const char* name, List* lst) {
    printf("%s = {", name);
    Node* p = lst->head;
    int first = 1;
    while (p) {
        if (!first) printf(", ");
        printf("%d", p->data);
        first = 0;
        p = p->next;
    }
    printf("}\n");
}

// 将值 val 添加到 result 表尾（不使用辅助表元）
static void append_value(List* result, Node** tail_ref, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    if (result->head == NULL) {
        result->head = node;
        *tail_ref = node;
    } else {
        (*tail_ref)->next = node;
        *tail_ref = node;
    }
}

// 1. 并集
void unionSet(struct List *s1, struct List *s2, struct List *result) {
    // 清空 result
    free_list(result);
    result->head = NULL;
    Node* p = s1->head;
    Node* q = s2->head;
    Node* tail = NULL;
    while (p && q) {
        if (p->data < q->data) {
            append_value(result, &tail, p->data);
            p = p->next;
        } else if (p->data > q->data) {
            append_value(result, &tail, q->data);
            q = q->next;
        } else { // equal
            append_value(result, &tail, p->data);
            p = p->next;
            q = q->next;
        }
    }
    while (p) { append_value(result, &tail, p->data); p = p->next; }
    while (q) { append_value(result, &tail, q->data); q = q->next; }
}

// 2. 差集 S1 \ S2
void differenceSet(struct List *s1, struct List *s2, struct List *result) {
    free_list(result);
    result->head = NULL;
    Node* p = s1->head;
    Node* q = s2->head;
    Node* tail = NULL;
    while (p && q) {
        if (p->data < q->data) {
            append_value(result, &tail, p->data);
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else { // equal -> 在 S2 中出现，跳过
            p = p->next;
            q = q->next;
        }
    }
    while (p) { append_value(result, &tail, p->data); p = p->next; }
}

// 3. 交集
void intersectionSet(struct List *s1, struct List *s2, struct List *result) {
    free_list(result);
    result->head = NULL;
    Node* p = s1->head;
    Node* q = s2->head;
    Node* tail = NULL;
    while (p && q) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            append_value(result, &tail, p->data);
            p = p->next;
            q = q->next;
        }
    }
}

int main() {
    List S1, S2, U, D, I;
    int a1[] = {2, 3, 5, 6};
    int a2[] = {3, 4, 6, 8};
    list_from_array(&S1, a1, sizeof(a1)/sizeof(a1[0]));
    list_from_array(&S2, a2, sizeof(a2)/sizeof(a2[0]));
    U.head = D.head = I.head = NULL;

    print_list("S1", &S1);
    print_list("S2", &S2);

    unionSet(&S1, &S2, &U);
    print_list("Union", &U);

    differenceSet(&S1, &S2, &D);
    print_list("Difference (S1 - S2)", &D);

    intersectionSet(&S1, &S2, &I);
    print_list("Intersection", &I);

    // 释放
    free_list(&S1);
    free_list(&S2);
    free_list(&U);
    free_list(&D);
    free_list(&I);
    return 0;
}

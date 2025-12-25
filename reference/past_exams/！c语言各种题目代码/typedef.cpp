#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void addTerm(Node** result, int coefficient, int exponent) {
    if (*result == NULL) {
        *result = createNode(coefficient, exponent);
    } else {
        Node* current = *result;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(coefficient, exponent);
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* current = NULL;

    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int coefficientSum = poly1->coefficient + poly2->coefficient;
            if (coefficientSum != 0) {
                addTerm(&result, coefficientSum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2) {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

void printPolynomial(Node* poly) {
    Node* current = poly;

    while (current != NULL) {
        printf("%d %d ", current->coefficient, current->exponent);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    int coefficient, exponent;
    while (1) {
        scanf("%d", &exponent);
        if (exponent == -1) {
            break;
        }
        scanf("%d", &coefficient);
        addTerm(&poly1, coefficient, exponent);
    }

    Node* poly2 = NULL;
    while (1) {
        scanf("%d", &exponent);
        if (exponent == -1) {
            break;
        }
        scanf("%d", &coefficient);
        addTerm(&poly2, coefficient, exponent);
    }

    Node* result = addPolynomials(poly1, poly2);
    printPolynomial(result);

    return 0;}

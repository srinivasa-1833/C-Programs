#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode *first = head;
    struct ListNode *second = head;
    struct ListNode *current = head;

    for (int i = 1; i < k; i++) {
        first = first->next;
    }

    current = first;

    while (current->next != NULL) {
        current = current->next;
        second = second->next;
    }

    int temp = first->val;
    first->val = second->val;
    second->val = temp;

    return head;
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int k = 2;

    head = swapNodes(head, k);
    printList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;

    while (curr) {
        while (curr->next && curr->val == curr->next->val)
            curr = curr->next;

        if (prev->next == curr)
            prev = prev->next;
        else
            prev->next = curr->next;

        curr = curr->next;
    }

    return dummy.next;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* oddEvenList(struct ListNode* head)
{
    // check input
    if (!head) {
        printf("invalid input!\n");
        return NULL;
    } if (!head->next) return head;

    struct ListNode *h_odd = head, *h_even = head->next;
    struct ListNode *p_odd = h_odd, *p_even = h_even;
    while(p_odd && p_even) {
        p_odd->next = p_odd->next->next;
        if (p_even->next) p_even->next = p_even->next->next;
        else p_even->next = NULL;
        p_odd = p_odd->next;
        p_even = p_even->next;
    }

    p_odd = h_odd;
    while(p_odd->next) p_odd = p_odd->next;
    p_odd->next = h_even;
    return h_odd;
}


void test_0328()
{
    struct ListNode A0, A1, A2, A3, A4, A5, A6;

    A0.val = 1; A1.val = 2; A2.val = 3; A3.val = 4; A4.val = 5; A5.val = 6; A6.val = 7;
    A0.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = &A5; A5.next = &A6; A6.next = NULL;  
    struct ListNode *p = oddEvenList(&A0);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
}
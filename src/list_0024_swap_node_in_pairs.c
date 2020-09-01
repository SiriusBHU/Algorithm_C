#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{

    // check input
    if (!head) {
        printf("invalid input!\n");
        return NULL;
    } else if (!head->next) return head;

    // swap the first node
    struct ListNode *p1 = head, *p2 = head->next;
    p1->next = p2->next;
    p2->next = p1;
    head = p2;

    // swap the residual
    struct ListNode *p_sta = head->next;
    while (p_sta->next && p_sta->next->next)
    {
        // set the needed swap node
        p1 = p_sta->next;
        p2 = p1->next;

        // swap p1, p2, link the start and end
        p1->next = p2->next;
        p2->next = p1;
        p_sta->next = p2;

        // move start node
        p_sta = p1;
    }
    return head;
}


void test_0024()
{
    struct ListNode headA, A1, A2, A3, A4, A5;

    headA.val = 1; A1.val = 2; A2.val = 3; A3.val = 4; A4.val = 5; A5.val = 6;
    headA.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = &A5; A5.next = NULL;  

    struct ListNode *p = swapPairs(&headA);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
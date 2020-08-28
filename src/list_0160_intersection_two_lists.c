#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    // check input
    if (!headA || !headB) {
        printf("invalid input!");
        return NULL;
    }

    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    unsigned int lenA = 0;
    unsigned int lenB = 0; 

    // find the diff of list A and B
    while (pA->next) {
        pA = pA->next;
        lenA ++;
    }
    while (pB->next) {
        pB = pB->next;
        lenB++;
    }

    pA = headA; pB = headB;
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff--) pA = pA->next;
    } else {
        int diff  = lenB - lenA;
        while (diff--) pB = pB->next;
    }

    while (pA && pB) {
        if ((uintptr_t)pA == (uintptr_t)pB) return pA;
        else {
            pA = pA->next; pB = pB->next;
        }
    }
    return NULL;
}


void test_0160()
{
    struct ListNode headA, A1, A2, A3, A4, A5;
    struct ListNode headB, B1, B2, B3, B4;

    headA.val = 1; A1.val = 2; A2.val = 3; A3.val = 4; A4.val = 5; A5.val = 6;
    headB.val = 7; B1.val = 8; B2.val = 9; B3.val = 10; B4.val = 11;
    headA.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = &A5; A5.next = NULL;  
    headB.next = &B1; B1.next = &B2; B2.next = &B3; B3.next = &B4; B4.next = &A2;

    struct ListNode *p = getIntersectionNode(&A5, &A5);
    printf("%d\n", p->val);    
}

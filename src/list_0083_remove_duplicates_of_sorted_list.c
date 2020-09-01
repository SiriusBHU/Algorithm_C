#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* head){

    // check input
    if (!head) {
        printf("invalid input!\n");
        return NULL;
    } else if (!head->next) return head;

    struct ListNode *cur_node=head;
    struct ListNode *next_node=head->next;
    while (1) {
        // if equal, only move next node
        // else, cur_node = next mode, move next node
        if (next_node) {
            if (cur_node->val != next_node->val) {
                cur_node->next = next_node;
                cur_node = next_node;
            }
            next_node = next_node->next;
        } else {
            cur_node->next = NULL;
            break;
        }
    }
    return head;
}


void test_0083()
{
    struct ListNode headA, A1, A2, A3, A4, A5;

    headA.val = 1; A1.val = 1; A2.val = 2; A3.val = 3; A4.val = 3; A5.val = 3;
    headA.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = &A5; A5.next = NULL;  

    struct ListNode *p = deleteDuplicates(&headA);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
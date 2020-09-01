#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head)
{
    // check input
    if (!head) {
        printf("invalid input!");
        return NULL;
    }

    // reverse
    struct ListNode *fore_node=NULL,  *cur_node=head, *latter_node=head->next;
    while (latter_node) {
        // reverse
        cur_node->next = fore_node;
        
        fore_node = cur_node;
        cur_node = latter_node;
        latter_node = latter_node->next;
    }
    cur_node->next = fore_node;
    return cur_node;
}


void test_0206()
{
    struct ListNode headA, A1, A2, A3, A4, A5;

    headA.val = 1; A1.val = 2; A2.val = 3; A3.val = 4; A4.val = 5; A5.val = 6;
    headA.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = &A5; A5.next = NULL;  

    struct ListNode *p = reverseList(&headA);
    printf("%d\n", p->val);    
}

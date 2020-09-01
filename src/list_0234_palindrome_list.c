#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* _reverse(struct ListNode* head)
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


bool isPalindrome(struct ListNode *head)
{
    // check input
    if (!head || !head->next) return true;

    unsigned int len = 0;
    struct ListNode *p = head;
    while (p) {
        len ++;
        p = p->next;
    }

    // calculate the start points to reverse the list
    int sta_step = len % 2 ? len / 2 + 1 : len / 2;
    struct ListNode *new_head = head;
    while (sta_step --) {
        new_head = new_head->next;
    }
    // reverse
    new_head = _reverse(new_head);
    
    // calculate the compare length and compare
    int cmp_len = len / 2;
    while (cmp_len--) {
        if (new_head->val != head->val) return false;
        new_head = new_head->next;
        head = head->next;
    }
    return true;
}


void test_0234()
{
    struct ListNode headA, A1, A2, A3, A4;
    struct ListNode headB, B1, B2, B3;

    headA.val = 1; A1.val = 2; A2.val = 3; A3.val = 2; A4.val = 1;
    headB.val = 1; B1.val = 1; B2.val = 2; B3.val = 1;
    headA.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = NULL;  
    headB.next = &B1; B1.next = &B2; B2.next = &B3; B3.next = NULL;

    if (isPalindrome(&headB)) {
        printf("is Palindrome!\n");
    } else {
        printf("not a Palindrome list!\n");
    }
}
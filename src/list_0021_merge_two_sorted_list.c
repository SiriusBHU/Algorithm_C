#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    // check input
    if (!l1 && !l2) {
        printf("invalid input!\n");
        return NULL;
    } 
    else if (!l1) return l2;
    else if (!l2) return l1;
    
    // Merge
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = head, *p1 = l1, *p2 = l2;
    while (p1 && p2) {
        if (p1->val <= p2->val) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    } 
    if (!p1) p->next = p2;
    else if (!p2) p->next = p1;
    
    return head->next;
}
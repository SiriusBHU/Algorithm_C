#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    // check input
    if (!head || n < 1) {
        printf("invalid input!\n");
        return NULL;
    }
    
    // find length
    struct ListNode *p = head;
    int len = 0;
    while (p) {
        len ++;
        p = p->next;
    } 
    
    // check validness of the removing node
    int node_idx = len - n;
    if (node_idx < 0) {
        printf("expected n should not be bigger than the length of list, but got n(=%d) > len(=%d)\n", n, len);
        return NULL;
    }
    
    if (node_idx == 0) return head->next;
    else {
        
        // find the fore node
        struct ListNode *q = head;
        while (node_idx-- > 1) q = q->next;
        
        // delete node
        q->next = q->next->next;
        return head;
    }
    

    
}
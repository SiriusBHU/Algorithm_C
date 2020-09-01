#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // check input, if one is NULL,
    // return the other
    if (!l1 && !l2) {
        printf("invalid input\n");
        return NULL;
    } 
    else if (!l1) return l2;
    else if (!l2) return l1;

    // find the length of each list
    // let the longer list be l1, the other be l2
    struct ListNode *p1 = l1, *p2 = l2; 
    unsigned int len1 = 0, len2 = 0;
    while (p1) {
        len1 ++;
        p1 = p1->next; 
    } while (p2) {
        len2 ++;
        p2 = p2->next;
    } if (len1 < len2) {
        int _tmp_len = len1; struct ListNode *_tmp_node = l1;
        len1 = len2; l1 = l2;
        len2 = _tmp_len; l2 = _tmp_node;  
    }
    
    // calculate the sum
    int diff = len1 - len2;
    int *sum = (int *)malloc(len1 * sizeof(int));
    for (int i = 0; i < diff; i++, l1 = l1->next) {
        sum[i] = l1->val;
    } for (int j = diff; j < len1; j++, l1 = l1->next, l2 = l2->next) {
        sum[j] = l1->val + l2->val;
    } for (int i = len1 - 1; i > 0; i --) {
        if (sum[i] >= 10) {
            sum[i - 1] += sum[i] / 10;
            sum[i] %= 10; 
        }
    }

    // FIXME
    for (int i=0; i<len1; i++) printf("%d ", sum[i]);
    printf("\n");

    // set the value of sum to a new list
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    if (sum[0] >= 10) {
        p->val = sum[0] / 10;
        sum[0] %= 10;
        struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->next = node;
        p = node;
    }
    for (int i = 0; i < len1; i++) {
        p->val = sum[i];
        if (i == len1 -1) {
            p->next = NULL;
            continue;
        }
        struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->next = node;
        p = node;
    }

    if (!memset((void *)sum, 0x0, len1 * sizeof(int))) {
        printf("[func: %s] -- [line: %d]: memset error in line %d", __FILE__, __LINE__);
        return NULL;
    } free(sum);
    return head;
}


void test_0445()
{
    struct ListNode headA, A1, A2, A3, A4;
    struct ListNode headB, B1, B2, B3, B4;

    headA.val = 2; A1.val = 2; A2.val = 3; A3.val = 4; A4.val = 5;
    headB.val = 7; B1.val = 8; B2.val = 9; B3.val = 6; B4.val = 2;
    headA.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = NULL;  
    headB.next = &B1; B1.next = &B2; B2.next = &B3; B3.next = &B4; B4.next = NULL;

    struct ListNode *p = addTwoNumbers(&headA, &headB);
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
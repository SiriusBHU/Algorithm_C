#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
    // check input
    if (k <= 0) {
        printf("invalid input!\n");
        return NULL;
    }

    unsigned int len = 0;
    struct ListNode *p = root;
    while (p) {
        len ++;
        p = p->next;
    }
    struct ListNode **arr = (struct ListNode **)malloc(k * sizeof(struct ListNode *));
    if (!memset((void *)arr, 0x0, k * sizeof(struct ListNode *))) {
        printf("[file: %s] -- [line: %d]: memory setting error !\n", __FILE__, __LINE__);
        return NULL;
    }
    
    struct ListNode *p_head = root, *p_tail = root;
    unsigned int step = len / ((unsigned int)k);
    unsigned int residual = len % ((unsigned int)k);
    if (!step) {
        for (int i = 0; i < residual; i++) {
            arr[i] = p_head;
            p_head = p_tail->next;
            p_tail->next = NULL;
            p_tail = p_head; 
        }
    } else {
        for (int i = 0; i < k; i ++) {
            for (int j = 0; j < step - 1 && p_tail; j ++) p_tail = p_tail->next;
            if (residual) {
                residual -= 1;
                p_tail = p_tail->next;
            }
            
            arr[i] = p_head;
            p_head = p_tail->next;
            p_tail->next = NULL;
            p_tail = p_head;
        }
    }
    *returnSize = k;
    return arr;
}


void test_0725()
{
    struct ListNode A0, A1, A2, A3, A4, A5, A6;
    struct ListNode headB, B1, B2, B3;

    A0.val = 1; A1.val = 2; A2.val = 3; A3.val = 4; A4.val = 5; A5.val = 6; A6.val = 7;
    headB.val = 1; B1.val = 1; B2.val = 2; B3.val = 1;
    A0.next = &A1; A1.next = &A2; A2.next = &A3; A3.next = &A4; A4.next = &A5; A5.next = &A6; A6.next = NULL;  
    headB.next = &B1; B1.next = &B2; B2.next = &B3; B3.next = NULL;
    int returnSize;
    struct ListNode **arr = splitListToParts(&A0, 6, &returnSize);
    printf("1");

}
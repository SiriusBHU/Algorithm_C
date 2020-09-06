#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void moveZeroes(int* nums, int numsSize)
{
    // check input
    if (!nums || numsSize <= 0) {
        printf("invalid input!\n");
        return;
    }

    unsigned int idx = 0, non_zero_cnt = 0;
    while (idx < numsSize) {
        if (nums[idx] != 0) {
            nums[non_zero_cnt] = nums[idx];
            non_zero_cnt ++;
        }
        idx ++;
    }
    for (int i = non_zero_cnt; i < numsSize; i ++) nums[i] = 0;
    return;
}
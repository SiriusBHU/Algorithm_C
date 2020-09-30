#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


int** matrixReshape(
    int** nums, int numsSize, int* numsColSize, 
    int r, int c, int* returnSize, int** returnColumnSizes)
{
    // check input
    if (!nums || numsSize < 0 || *numsColSize < 0 || 
        r < 0 || c < 0) {
        printf("invalid input!\n");
        return NULL;
    }

    // check dimension alignment
    if (numsSize * (*numsColSize) != r * c) {
        printf("dims of %d can not be reshaped as (%d, %d)", 
               numsSize * (*numsColSize), r, c);
        *returnSize = numsSize;
        *returnColumnSizes = (int *)malloc(numsSize * sizeof(int));
        int i; 
        for (i = 0; i < numsSize; i++)
            (*returnColumnSizes)[i] = *numsColSize;
        return nums;
    }

    // malloc new 2-dim pointer
    int *arr = (int *)malloc(r * c * sizeof(int));
    uint32_t i, j;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < (*numsColSize); j ++) {
            arr[i * numsSize + j] = nums[i][j];
        }
    }

    // assign pointer
    int **new_nums = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i ++) 
        new_nums[i] = &arr[i * c];

    *returnSize = r;
    *returnColumnSizes = (int *)malloc(r * sizeof(int));
    for (i = 0; i < r; i ++) 
        (*returnColumnSizes)[i] = c;

    return new_nums;
}

void test_0583()
{
    int a[2][2] = 

}
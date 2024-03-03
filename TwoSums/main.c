#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    returnSize = (int*) malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsSize; ++j) {
            if (i != j && (nums[i] + nums[j]) == target) {
                returnSize[0] = i;
                returnSize[1] = j;
            }
        }
    }

    return returnSize;
}

int main() {
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int * ret;

    int* resultado = twoSum(nums, 4, target, ret);
    printf("%d, %d", resultado[0], resultado[1]);
    free(resultado);

}

#include <stdlib.h>
#include <stdio.h>

int* getTwoHeviest(int* stones, int stonesSize) {
    int* twoHeaviest = (int*) malloc(2 * sizeof(int));
    twoHeaviest [0] = twoHeaviest[1] = 0;

    for (int i = 0; i < stonesSize; ++i) {
        if (stones[i] >  stones[twoHeaviest[0]]) {
            twoHeaviest[1] = twoHeaviest[0];
            twoHeaviest[0] = i;
        } else if (stones[i] > stones[twoHeaviest[1]]) {
            twoHeaviest[1] = i;
        }
    }

    return twoHeaviest;
}

int* destroyStones(int* stones, int stonesSize) {
    int* maxStonesIndex = getTwoHeviest(stones, stonesSize);
    int* result = (int*) malloc(stonesSize - 3 * sizeof(int));
    int j = 0;
    for (int i = 0; i < stonesSize; ++i) {
        if (i != maxStonesIndex[0] && i != maxStonesIndex[1]) {
            result[j] = stones[i];
            j++;
        }
    }
    return result;
}

int* clashStones(int* stones, int stonesSize) {
    int* maxStonesIndex = getTwoHeviest(stones, stonesSize);
    int result = stones[maxStonesIndex[0]] - stones[maxStonesIndex[1]];
    int* resultArray = (int*) malloc(stonesSize - 2 * sizeof(int));
    int j = 0;
    for (int i = 0; i < stonesSize; ++i) {
        if (i != maxStonesIndex[0]) {
            if (i == maxStonesIndex[1]) {
                resultArray[j] = result;
            }
            resultArray[j] = stones[i];
            j++;
        }
    }

    return resultArray;
}

int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        stones = clashStones(stones, stonesSize);
        stonesSize--;
    }
    return stones[0];
}


int main() {
    int stones[6] = {2, 7, 4, 1, 8, 1};

    printf("Resultado: %d\n", lastStoneWeight(stones, 6));
}

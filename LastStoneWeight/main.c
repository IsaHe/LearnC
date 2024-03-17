#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getTwoHeviest(int* stones, int stonesSize, int *heviest0, int *heviest1) {
    *heviest0 = 0;
    *heviest1 = 1;

    for (int i = 0; i < stonesSize; ++i) {
        if (stones[i] > stones[*heviest0]) {
            *heviest1 = *heviest0;
            *heviest0 = i;
        } else if (stones[i] > stones[*heviest1]) {
            *heviest1 = i;
        }
    }
}

int* destroyStones(int* stones, int *stonesSize, int heviest0, int heviest1) {
    *stonesSize -= 1;
    int* newStones = malloc(sizeof(int) * (*stonesSize));
    int j = 0;
    for (int i = 0; i <= *stonesSize; ++i) {
        if (i != heviest1 && i != heviest0) newStones[j] = stones[i]; j++;
    }
    free(stones);
    return newStones;
}

int* clashStones(int* stones, int *stonesSize, int heviest0, int heviest1) {
    *stonesSize -= 1;
    int* newStones = malloc(sizeof(int) * (*stonesSize));
    int j = 0;
    for (int i = 0; i <= *stonesSize; i++) {
        if (i != heviest1) {
            newStones[j] = (i != heviest0) ? stones[i] : stones[heviest0] - stones[heviest1];
            j++;
        }
    }
    free(stones);
    return newStones;
}

int* vsStones(int* stones, int *stonesSize) {
    int heviest0, heviest1;
    getTwoHeviest(stones, *stonesSize, &heviest0, &heviest1);
    if(heviest1 == heviest0) return destroyStones(stones, stonesSize, heviest0, heviest1);
    return clashStones(stones, stonesSize, heviest0, heviest1);
}

void printStoneArray(int* stones, int stonesSize) {
    for (int i = 0; i < stonesSize; ++i) {
        printf("(%d)%d; ", i, stones[i]);
    }
    printf("\b\b\n");
}

int lastStoneWeight(int* stones, int stonesSize) {
    int* newStones = malloc(sizeof(int) * stonesSize);
    memcpy(newStones, stones, sizeof(int) * stonesSize);
    while (stonesSize > 1) {
        printStoneArray(newStones, stonesSize);
        newStones = vsStones(newStones, &stonesSize);
    }

    int lastWeight = newStones[0];
    free(newStones);
    return lastWeight;
}

int lastStoneWeightBetter(int* stones, int stonesSize) {
    int i;
    int max1, max2;
    int max1_index, max2_index;
    int temp;
    while(stonesSize > 1)
    {
        max1 = 0;
        max2 = 0;
        max1_index = 0;
        max2_index = 0;
        for(i = 0; i < stonesSize; i++)
        {
            if(stones[i] > max1)
            {
                max1 = stones[i];
                max1_index = i;
            }
        }
        temp = stones[stonesSize - 1];
        stones[stonesSize - 1] = max1;
        stones[max1_index] = temp;
        for(i = 0; i < stonesSize - 1; i++)
        {
            if(stones[i] > max2)
            {
                max2 = stones[i];
                max2_index = i;
            }
        }
        stones[max2_index] = max1 - max2;
        stonesSize--;
    }
    return stones[0];

}

int getNonCeroedElements(int* stones, int stonesSize) {
    int total = 0;
    for (int i = 0; i < stonesSize; ++i) {
        if (stones[i] != 0) total++;
    }
    return total;
}

int lastStoneWeightBetterMine(int* stones, int stonesSize) {
    int max0, max1;
    int nonCeroed = stonesSize;
    while (nonCeroed != 1) {
        printStoneArray(stones, stonesSize);
        nonCeroed = getNonCeroedElements(stones, stonesSize);
        getTwoHeviest(stones, stonesSize, &max0, &max1);
        printf("%d, %d\n", max0, max1);
        int result = stones[max0] - stones[max1];

        if (result == 0) {
            stones[max0] = stones[max1] = 0;
        } else {
            stones[max1] = 0;
            stones[max0] = result;
        }
    }
    return stones[stonesSize-1];
}


int main() {
    int stones[2] = {3, 1};
    int stoneSize = 2;
    int lastWeight = lastStoneWeightBetterMine(stones, stoneSize);
    printf("%d", lastWeight);
    return 0;
}

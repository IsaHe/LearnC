#include <stdlib.h>
#include <stdio.h>

void getTwoHeviest(int* stones, int stonesSize, int *heviest0, int *heviest1) {
    *heviest0 = stones[0];
    *heviest1 = stones[1];

    for (int i = 0; i < stonesSize; ++i) {
        if (stones[i] > stones[*heviest0]) {
            *heviest1 = *heviest0;
            *heviest0 = i;
        } else if (stones[i] > stones[*heviest1]) {
            *heviest1 = i;
        }
    }
}

int* destroyStones(const int* stones, int *stonesSize, int heviest0, int heviest1) {
    *stonesSize -= 1;
    int* newStones = malloc(sizeof(int) * (*stonesSize));
    int j = 0;
    for (int i = 0; i <= *stonesSize; ++i) {
        if (i != heviest1 && i != heviest0) newStones[j] = stones[i]; j++;
    }
    return newStones;
}

int* clashStones(const int* stones, int *stonesSize, int heviest0, int heviest1) {
    *stonesSize -= 1;
    int* newStones = malloc(sizeof(int) * (*stonesSize));
    int j = 0;
    for (int i = 0; i <= *stonesSize; i++) {
        if (i != heviest1) {
            newStones[j] = (i != heviest0) ? stones[i] : stones[heviest0] - stones[heviest1];
            j++;
        }
    }
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
        printf("%d; ", stones[i]);
    }
    printf("\b\b\n");
}

int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        printStoneArray(stones, stonesSize);
        stones = vsStones(stones, &stonesSize);
    }

    return stones[0];
}


int main() {
    int stones[6] = {2, 7, 4, 1, 8, 1};
    int stoneSize = 6;
    int lastWeight = lastStoneWeight(stones, stoneSize);
    printf("%d", lastWeight);
    return 0;
}

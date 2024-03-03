#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void sortArray(int * arr, int len) {
    for (int i = 0; i < len-1; ++i) {
        arr[i] = (arr[i+1] > arr[i]) ? arr[i+1] : arr[i];
    }
}

int * squareArray(int *arr, int len) {
    int * result = (int*) malloc(sizeof(int) * len);

    for (int i = 0; i < len; ++i) {
        result[i] = floor(pow(arr[i], 2));
    }

    sortArray(result, 5);

    return result;
}



int main() {

    int arr[] = {-4, -1, 0, 3, 10};
    int *sqred = squareArray(arr, 5);

    for (int i = 0; i < 5; ++i) {
        printf("%d, ", sqred[i]);
    }

    free(sqred);

  return 0;
}

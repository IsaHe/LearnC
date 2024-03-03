#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void sortArray(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    int *sqred = squareArray(arr, 5); // {16, 1, 0, 9, 100}

    for (int i = 0; i < 5; ++i) {
        printf("%d, ", sqred[i]);
    }

    free(sqred);

  return 0;
}

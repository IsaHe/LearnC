#include <stdio.h>
#include <stdlib.h>

void imprimirArray2Dc(int **array, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}

void liberarArray2D(int **array, int x) {
    for (int i = 0; i < x; ++i) {
        free(array[i]);
    }
    free(array);
}

int main(){
    int X = 4;
    int Y = 3;

    // EJERCICIO 17a
    int a[X][Y];
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            a[i][j] = i*j;
        }
    }

    // EJERCICIO 17c
    int ** c = (int **)malloc(X * sizeof(int *));
    for (int i = 0; i < X; ++i) {
        c[i] = (int *) malloc(Y * sizeof(int));
    }
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            c[i][j] = i*j;
        }
    }

    imprimirArray2Dc(c, X, Y);

    liberarArray2D(c, X);
}

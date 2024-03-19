#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

int compare( const void* a, const void* b) {
    int* int_a = *((int **) a);
    int* int_b = *((int **) b);

    return (int_a[0] < int_b[0]) ? -1 : 1;
}

void printPoints(int** points, int pointsSize) {
    for (int i = 0; i < pointsSize; ++i) {
        printf("[%d, %d]\n", points[i][0], points[i][1]);
    }
    printf("\n");
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {

    if (!pointsSize) return 0;
    int minArrows = 1;

    qsort(points, pointsSize, sizeof(int*), compare);
    printPoints(points, pointsSize);
    int end = (*points)[1];
    points++;
    pointsSize--;

    while (pointsSize) {
        if ((*points)[0] > end) {
            end = (*points)[1];
            minArrows++;
        } else {
            end = ((*points)[1] > end) ? end : (*points)[1];
        }
        points++;
        pointsSize--;
    }
    return minArrows;
}

int** example1() {
    int** points = (int**) malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        points[i] = (int*) malloc(2 * sizeof(int));
    }
    points[0][0] = 10;
    points[0][1] = 16;
    points[1][0] = 2;
    points[1][1] = 8;
    points[2][0] = 1;
    points[2][1] = 6;
    points[3][0] = 7;
    points[3][1] = 12;
    return points;
}

int** example2() {
    int** points = (int**) malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        points[i] = (int*) malloc(2 * sizeof(int));
    }
    points[0][0] = 1;
    points[0][1] = 2;
    points[1][0] = 3;
    points[1][1] = 4;
    points[2][0] = 5;
    points[2][1] = 6;
    points[3][0] = 7;
    points[3][1] = 8;
    return points;
}

int** example3() {
    int** points = (int**) malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        points[i] = (int*) malloc(2 * sizeof(int));
    }
    points[0][0] = 1;
    points[0][1] = 2;
    points[1][0] = 2;
    points[1][1] = 3;
    points[2][0] = 3;
    points[2][1] = 4;
    points[3][0] = 4;
    points[3][1] = 5;
    return points;
}

int main() {

    int** points = example2();

    int pointsColSize[4] = {2, 2,2 , 2};

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    printf("%d\n", findMinArrowShots(points, 4, pointsColSize));

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El tiempo de ejecución fue %f segundos\n", cpu_time_used);
    //Imprime el tiempo de ejecución en milisegundos
    printf("El tiempo de ejecución fue %f milisegundos\n", cpu_time_used*1000);

    for (int i = 0; i < 4; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}

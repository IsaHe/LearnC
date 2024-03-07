#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

void imprimirPunto(Point p){
    printf("(%d, %d)\n", p.x, p.y);
}

int main(){
    Point ***array = (Point ***)malloc(5 * sizeof(Point **));
    for (int i = 0; i < 5; i++){
        array[i] = (Point **)malloc(4 * sizeof(Point *));
        for (int j = 0; j < 4; j++){
            array[i][j] = (Point *)malloc(3 * sizeof(Point));
        }
    }

    array[2][3][1].y = 3;
    array[2][3][1].y = 4;
    imprimirPunto(array[2][3][1]);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);

}

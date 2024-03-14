#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

int main(){

    FILE *f;
    Point points[3] = {{1.0f, 2.0f}, {3.0f, 4.0f}, {5.0f, 6.0f}};
    Point pointsRead[3];
    int size = sizeof(Point);
    int n = 3;

    f = fopen("file.bin", "wb");
    if (f == NULL){
        printf("Error al abrir el archivo");
        return 1;
    }

    fwrite(points, size, n, f);
    fclose(f);

    f = fopen("file.bin", "rb");
    if (f == NULL){
        printf("Error al abrir el archivo");
        return 1;
    }

    fread(pointsRead, size, n, f);
    fclose(f);

    for (int i = 0; i < n; i++){
        printf("Point %d: (%f, %f)\n", i, pointsRead[i].x, pointsRead[i].y);
    }

    return 0;
}

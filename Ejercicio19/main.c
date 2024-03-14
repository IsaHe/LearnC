#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fichero;
    int N = 10;
    fichero = fopen("fichero.txt", "w");
    for (int i = 1; i <= N; i++){
        fprintf(fichero, "%d\n", i);
    }
    fclose(fichero);

    fichero = fopen("fichero.txt", "r");
    int c;
    int lineas = 0;
    while ((c = fgetc(fichero)) != EOF){
        putchar(c);
        if (c == '\n'){
            lineas++;
        }
    }
    printf("Total de lineas leidas: %d\n", lineas);
    fclose(fichero);
    return 0;
}

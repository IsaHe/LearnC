#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    printf("%d\n", argc);
    for (int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    if (strcmp(argv[1], "Hola") == 0){
        printf("Hola\n");
    } else {
        printf("Adios\n");
    }
}

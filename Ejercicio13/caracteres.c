#include <stdio.h>
#include "caracteres.h"

int obtenerTamanyo(char *cadena) {
    int tamanyo = 0;
    while (cadena[tamanyo] != '\0') {
        tamanyo++;
    }
    return tamanyo;
}

void imprimirCaracteres(char *cadena) {
    // imprimir cada uno de los caracteres de la cadena por separado
    int tamanyo = obtenerTamanyo(cadena);
    for (int i = 0; i < tamanyo; ++i) {
        printf("%c", cadena[i]);
    }
    printf("\n");
}

void clonarCadena(char *cadena1, char *cadena2) {
    int tamanyo = obtenerTamanyo(cadena1);
    for (int i = 0; i < tamanyo + 1; ++i) {
        cadena2[i] = cadena1[i];
    }
}

void concatenarCadenas(char *cadena1, char *cadena2) {
    int tamanyo1 = obtenerTamanyo(cadena1);
    int tamanyo2 = obtenerTamanyo(cadena2);
    for (int i = 0; i < tamanyo2 + 1; ++i) {
        cadena1[tamanyo1 + i] = cadena2[i];
    }
}

void copiarCadena(char *cadena1, char *cadena2) {
    int tamanyo = obtenerTamanyo(cadena1);
    for (int i = 0; i < tamanyo + 1; ++i) {
        cadena2[i] = cadena1[i];
    }
}

#include <stdint.h>

#include <stdint.h> // Incluye la biblioteca stdint.h que proporciona un conjunto de tipos de enteros de ancho fijo.

int lengthOfLongestSubstring(char* s) { // Define la función lengthOfLongestSubstring que toma un puntero a una cadena de caracteres como argumento.
    uint32_t lh = 0; // Declara una variable de 32 bits sin signo llamada lh e inicialízala en 0. Esta variable se utiliza para almacenar la presencia de caracteres con un valor ASCII menor a 64 en la cadena.
    uint64_t hh = 0; // Declara una variable de 64 bits sin signo llamada hh e inicialízala en 0. Esta variable se utiliza para almacenar la presencia de caracteres con un valor ASCII mayor o igual a 64 en la cadena.
    int length = 0; // Declara una variable entera llamada length e inicialízala en 0. Esta variable se utiliza para almacenar la longitud de la subcadena más larga encontrada hasta ahora.
    char *sh = s; // Declara un puntero a char llamado sh y apúntalo al inicio de la cadena. Este puntero se utiliza para apuntar al inicio de la subcadena actual.

    while(*s) { // Inicia un bucle que se ejecuta hasta que se encuentra el carácter nulo en la cadena.
        if(*s < 64) { // Si el valor ASCII del carácter actual es menor a 64, entra en este bloque.
            uint32_t lhh = (uint32_t)(((uint32_t)1) << (((uint32_t)(*s))-32)); // Calcula el valor de lhh que es básicamente un número con un solo bit en la posición correspondiente al valor ASCII del carácter.
            if((lh & lhh) == 0) { // Si el bit correspondiente al carácter en lh no está activado, entra en este bloque.
                lh |= lhh; // Activa el bit correspondiente al carácter en lh.
                s++; // Incrementa el puntero s para apuntar al siguiente carácter en la cadena.
                length = (s-sh) > length ? (s-sh) : length; // Si la longitud de la subcadena actual es mayor que la longitud almacenada en length, actualiza length.
                continue; // Salta a la siguiente iteración del bucle.
            }
            goto adjust; // Si el bit correspondiente al carácter en lh ya está activado, salta a la etiqueta adjust.
        } else { // Si el valor ASCII del carácter actual es mayor o igual a 64, entra en este bloque.
            uint64_t hhh = (uint64_t)(((uint64_t)1) << (((uint64_t)(*s))-64)); // Calcula el valor de hhh que es básicamente un número con un solo bit en la posición correspondiente al valor ASCII del carácter.
            if((hhh & hh) == 0) { // Si el bit correspondiente al carácter en hh no está activado, entra en este bloque.
                hh |= hhh; // Activa el bit correspondiente al carácter en hh.
                s++; // Incrementa el puntero s para apuntar al siguiente carácter en la cadena.
                length = (s-sh) > length ? (s-sh) : length; // Si la longitud de la subcadena actual es mayor que la longitud almacenada en length, actualiza length.
                continue; // Salta a la siguiente iteración del bucle.
            }
            goto adjust; // Si el bit correspondiente al carácter en hh ya está activado, salta a la etiqueta adjust.
        }
        adjust: // Esta es la etiqueta adjust.
        if(*sh < 64) { // Si el valor ASCII del carácter al que apunta sh es menor a 64, entra en este bloque.
                lh ^= (uint32_t)(((uint32_t)1) << (((uint32_t)(*sh))-32)); // Desactiva el bit correspondiente al carácter en lh.
                sh++; // Incrementa el puntero sh para apuntar al siguiente carácter en la cadena.
        } else { // Si el valor ASCII del carácter al que apunta sh es mayor o igual a 64, entra en este bloque.
                hh ^= (uint64_t)(((uint64_t)1) << (((uint64_t)(*sh))-64)); // Desactiva el bit correspondiente al carácter en hh.
                sh++; // Incrementa el puntero sh para apuntar al siguiente carácter en la cadena.
        }
    }
    return length; // Devuelve la longitud de la subcadena más larga sin caracteres repetidos.
}



int main() {

    char* string = "";
    unsigned int maxLenght = lengthOfLongestSubstring(string);

    return 0;
}
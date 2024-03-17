#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

// Función de utilidad para inicializar la stack
struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}

// Función de utilidad para devolver el tamaño de la stack
int size(struct stack *pt) {
    return pt->top + 1;
}

// Función de utilidad para verificar si la stack está vacía o no
int isEmpty(struct stack *pt) {
    return pt->top == -1;                   // o return size(pt) == 0;
}

// Función de utilidad para verificar si la stack está llena o no
int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;      // o return size(pt) == pt->maxsize;
}

// Función de utilidad para agregar un elemento `x` a la stack
void push(struct stack *pt, int x)
{
    // comprobar si la stack ya está llena. Entonces insertar un elemento sería
    // conduce al desbordamiento de la stack
    if (isFull(pt))
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Inserting %d\n", x);

    // agrega un elemento e incrementa el índice de la parte superior
    pt->items[++pt->top] = x;
}

// Función de utilidad para devolver el elemento superior de la stack
int peek(struct stack *pt)
{
    // comprobar si hay una stack vacía
    if (!isEmpty(pt)) {
        return pt->items[pt->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// Función de utilidad para sacar un elemento superior de la stack
int pop(struct stack *pt)
{
    // comprobar si hay subdesbordamiento de stack
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Removing %d\n", peek(pt));

    // disminuye el tamaño de la stack en 1 y (opcionalmente) devuelve el elemento extraído
    return pt->items[pt->top--];
}

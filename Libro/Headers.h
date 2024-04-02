//
// Created by Isaac Herbozo on 15/3/24.
//
#ifndef LEARNING_HEADERS_H
#define LEARNING_HEADERS_H

// Estructura de datos para representar una stack
struct stack
{
    int maxsize;    // define la capacidad máxima de la stack
    int top;
    int *items;
};

char *alloc(int n);
void afree(char *p);
int strlen0(char *s);
unsigned long strlen1(char *s);
void strCpyStd (char *s, char *t);
void strCpyPointers (char *s, char *t);
void strCpyPointersPretty (char *s, char *t);
void strCpyPointersPrettyer (char *s, char *t);
int strcmpStd(char *s, char *t);
int strCmpPointer(char *s, char *t);
void strcatPointer(char *s, char *t);
int strend(char *s, char*t);
int size(struct stack *pt);
int isEmpty(struct stack *pt);
int isFull(struct stack *pt);
void push(struct stack *pt, int x);
int peek(struct stack *pt);
int pop(struct stack *pt);
struct stack* newStack(int capacity);
void copy();
void countInput();

#endif //LEARNING_HEADERS_H

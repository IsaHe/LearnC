
#include <stdio.h>
#include "Headers.h"

void copy() {
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

void countInput() {

    double nc;

    for (nc = 0; getchar() != EOF; nc++);

    printf("%.0f\n", nc);
}

void countNewLine() {
    long nl = 0;
    int c;

    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;

    printf("%ld\n", nl);
}
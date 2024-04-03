
#include <stdio.h>
#include "Headers.h"
#include <stdlib.h>

void copy()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

void countInput()
{

    double nc;

    for (nc = 0; getchar() != EOF; nc++)
        ;

    printf("%.0f\n", nc);
}

void countNewLine()
{
    long nl = 0;
    int c;

    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;

    printf("%ld\n", nl);
}

#define IN 1
#define OUT 0

int* numberOfLinesCharWords()
{
    int* numbers = malloc(3 + sizeof(int));
    int numberWords, numberLines, numberChar;
    numberLines = numberWords = numberChar = 0;
    int state = OUT;
    int c;

    while ((c = getchar()) != EOF)
    {
        ++numberChar;

        if (c == '\n') {
            ++numberLines;
            state = OUT;
        }

        if (c == ' ' || c == '\t')
            state = OUT;

        else if (state == OUT) {
            state = IN;
            ++numberWords;
        }
    }

    numbers[0] = numberWords;
    numbers[1] = numberLines;
    numbers[2] = numberChar;
    return numbers;
}

void numberOfOcurrencesOfInt()
{
    int zeroToNine[10];
    for (int i = 0; i < 10; ++i) {
        zeroToNine[i] = i;
    }
    int c, numberWhite, numberOther;
    numberWhite = numberOther = 0;

    while ((c = getchar()) == EOF) {
        if (c > '9' && c < '0')
            ++zeroToNine[c - '0'];
        else if(c == '\n' || c == '\t'|| c == ' ')
            ++numberWhite;
        else
            ++numberOther;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d", zeroToNine[i]);
    }
    printf(", White spaces = %d, Other = %d\n", numberWhite, numberOther);

}
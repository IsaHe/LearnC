#include <stdio.h>
#include "Headers.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

void printCommands(){
    printf("Hello, World!\n Next line\n");
    printf("Hello, World!\b Backspace\n");
    printf("Hello, World!\t Tab\n");
    printf("Hello, World!\v Vertical tab\n");
    printf("Hello, World!\r Carriage return\n");
    printf("Hello, World!\f Form feed\n");
    printf("Hello, World!\a Alert\n");
    printf("Hello, World!\\ Backslash\n");
    printf("Hello, World!\' Single quote\n");
    printf("Hello, World!\" Double quote\n");
    printf("Hello, World!\? Question mark\n");
}

//int main(int argc, char *argv[])
//{
//    if (argc == 1) return 1;
//
//    struct stack* stack = newStack(argc-1);
//    int temp;
//
//    while (--argc > 0) {
//        argv++;
//        switch (**argv) {
//            case '-':
//                temp = pop(stack);
//                temp = pop(stack) - temp;
//                push(stack, temp);
//                break;
//            case '*':
//                temp = pop(stack);
//                temp *= pop(stack);
//                push(stack, temp);
//                break;
//            case '+':
//                temp = pop(stack);
//                temp += pop(stack);
//                push(stack, temp);
//                break;
//            default:
//                push(stack, atoi(*argv));
//                break;
//        }
//    }
//
//    printf("%d", peek(stack));
//    return 0;
//}

void lowerImput() {
    int c;
    while ((c = getchar()) != EOF)
        putchar(tolower(c));
}

void minPrintf(char *fmt, ...) {
    {
        va_list ap;   /* points to each unnamed arg in turn */
        char *p, *sval;
        int ival;
        double dval;
        va_start(ap, fmt); /* make ap point to 1st unnamed arg */
        for (p = fmt; *p; p++) {
            if (*p != '%') {
                putchar(*p);
                continue;
            }
            switch (*++p) {
                case 'd':
                    ival = va_arg(ap, int);
                    printf("%d", ival);
                    break;
                case 'f':
                    dval = va_arg(ap, double);
                    printf("%f", dval);
                    break;
                case 's':
                    for (sval = va_arg(ap, char *); *sval; sval++)
                        putchar(*sval);
                    break;
                default:
                    putchar(*p);
                    break;
            }
        }
        va_end(ap);   /* clean up when done */
    }
}

int main() {

    return 0;
}

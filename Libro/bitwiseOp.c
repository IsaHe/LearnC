#include <stdio.h>
// BITWISE OPERATORS = special operators used in bit level programming
//                                          (knowing binary is important for this topic)

// & = AND
// | = OR
// ^ = XOR
// <<  left shift
// >>  right shift


void bitOp() {
    int x = 6;  //    6 = 00000110
    int y = 12; // 12 = 00001100
    int z = 0;  //    0 = 00000000

    z = x & y;
    printf("AND = %d\n", z);

    z = x | y;
    printf("OR = %d\n", z);

    z = x ^ y;
    printf("XOR = %d\n", z);

    z = x << 1;
    printf("SHIFT LEFT = %d", z);

    z = x >> 1;
    printf("SHIFT RIGHT = %d", z);
}
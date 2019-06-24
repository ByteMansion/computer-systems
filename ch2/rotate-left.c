/**
 * @file    rotate.-left.c
 *
 * @brief   2.69
 *  Do rotating left shift.
 *  Assume 0 <= n < w
 *  Examples when x = 0x12345678 and w = 32:
 *      n=4 -> 0x23456781, n=20 -> 0x67812345
 *
 */
#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    // if n == 0, w-n will be the width of left oprand and the behavior is undefined.
    // so we need right shift 2 times
    return (x << n) | ((x >> (w - n - 1)) >> 1);
}

int main(int argc, char** argv)
{
    unsigned long w = sizeof(int) << 3;
    unsigned x = 0x12345678;
    printf("x = %x\n", x);

    for(int i = 0; i < w; ++i) {
        printf("rotate: %d, result: 0x%x\n", i, rotate_left(x, i));
    }

    return 0;
}


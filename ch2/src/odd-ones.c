/**
 * @file    odd-ones.c
 *
 * @brief   2.65
 *  int has 32 bits
 *  at most 12 arithmetic, bitwise, and logical operations
 *
 * @return
 *  1: x contains an odd number of 1
 *  0: otherwise
 */
#include <stdio.h>

int odd_ones(unsigned x)
{
    // magic method
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x &= 0x0f;   // get the number of 1
    return (0x6996 >> x) & 1;

}

int main(int argc, char **argv)
{
    // unsigned x = 0x12345678;
    unsigned x = 0xAA;
    if(odd_ones(x)) {
        printf("Integer 0x%x has odd number of 1s!\n", x);
    } else {
        printf("Integer 0x%x has even number of 1s!\n", x);
    }

    return 0;
}

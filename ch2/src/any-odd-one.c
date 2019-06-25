/**
 * @file    any-odd-one.c
 *
 * @brief   2.64
 *  assume w = 32
 *
 * @return
 *  1: when any odd bit of x equals 1
 *  0: otherwise
 */
#include <stdio.h>

int any_odd_one(unsigned x)
{
    unsigned mask = 0xAAAAAAAA;
    return (x & mask) == mask;
}

int main(int argc, char **argv)
{
    // unsigned x = 0x12345678;
    unsigned x = 0xABABABAB;
    if(any_odd_one(x)) {
        printf("Any odd bit of 0x%x is 1!\n", x);
    } else {
        printf("Not all odd bits of 0x%x is 1.\n", x);
    }

    return 0;
}

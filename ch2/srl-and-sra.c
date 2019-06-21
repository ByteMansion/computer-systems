/**
 * @file    srl-and-sra.c
 *
 * @brief   2.63
 *  implement logical right shift using arithmetic shift
 *  and vice versa
 *
 */
#include <stdio.h>

#define INTBITS (sizeof(int) << 3)

unsigned srl(unsigned x, int k)
{
    // Perform shift arithmetically
    unsigned xsra = (int) x >> k;
    unsigned mask = (unsigned)(-1) << (INTBITS - k);

    return (xsra & (~mask));
}

int sra(int x, int k)
{
    // Perform shift logically
    int xsrl = (unsigned) x >> k;

    int mask = (int)(-1) << (INTBITS - k);
    int m = 1 << (INTBITS - 1);
    mask &= !(x & m) - 1;  // first bit of x is 1, mask remain unchanged, otherwise 0

    return (xsrl | mask);
}

int main(int argc, char** argv)
{
    unsigned unsigned_num = 0x12345678;
    int signed_num = 0x12345678;

    if(srl(unsigned_num, 4) == unsigned_num >> 4) {
        printf("Logical right shift succeeds using arithmetic shift!\n");
    }

    if(sra(signed_num, 4) == signed_num >> 4) {
        printf("Arithmetic right shift succeeds using logical shift!\n");
    }

    return 0;
}

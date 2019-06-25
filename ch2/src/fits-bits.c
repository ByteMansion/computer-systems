/**
 * @file    fits-bits.c
 *
 * @brief   2.70
 *  Assume 1 <= n <= w
 *
 * @return
 *  1: x can be represented as an n-bits, 2's-complement number
 *  0: otherwise
 *
 */
#include <stdio.h>

int fits_bits(int x, int n)
{
    x = ((unsigned)x >> (n - 1)) >> 1;
    return !(x & 0xffffffff);
}

int main(int argc, char** argv)
{
    int x = 0x1234567;
    int w = sizeof(int) << 3;
    for(int i = 1; i <= w; ++i) {
        if(fits_bits(x, i)) {
            printf("0x%x can be represented as %d bits.\n", x, i);
        } else {
            printf("0x%x can NOT be represented as %d bits.\n", x, i);
        }
    }

    return 0;
}

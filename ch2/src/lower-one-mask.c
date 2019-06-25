/**
 * @file    lower-one-mask.c
 *
 * @brief   2.68
 *  Mask with least significant n bits set to 1
 *  Examples: n = 6 -> 0x3f, n = 17 -> 0x1FFFF
 *  Assume 1 <= n <= w
 */
#include <stdio.h>

int lower_one_mask(int n)
{
    unsigned x = 1 << (n - 1);

    return (x << 1) - 1;
}

int main(int argc, char **argv)
{
    unsigned long w = sizeof(int) << 3;
    for(int i = 1; i <= w; ++i) {
        printf("i = %d, mast = 0x%x\n", i, lower_one_mask(i));
    }

    return 0;
}

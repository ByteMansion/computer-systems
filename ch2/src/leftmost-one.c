/**
 * @file    leftmost-one.c
 *
 * @brief   Generate mask indicating leftmost 1 in x.
 *  If x = 0, then return 0.
 *  0xFF00 -> 0x8000
 *
 */
#include <stdio.h>

int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    /**
     * Then mask can be got if (x >> 1) and then add 1
     * e.g. 0111 -> 0011 -> 0100
     * !Note: we have to tackle the special case (x = 0)
     * If x is 0, add 1 is not correct.
     */
    return (x >> 1) + (x && 1);
}

int main(int argc, char **argv)
{
    unsigned test[5] = {0, 0xFF00, 0x123456, 0x0012, 0x30125034};

    for(int i = 0; i < 5; ++i) {
        printf("original number: 0x%x, mask number: 0x%x\n", test[i], leftmost_one(test[i]));
    }

    return 0;
}

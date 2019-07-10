/**
 * @file    high-prod.c
 *
 * @brief   2.75
 *  Compute high-oder bits of x*y.
 *
 */
#include <stdio.h>
#include <inttypes.h>

static int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);

    return signed_prod + x * sig_y + y * sig_x;
}

int main(int argc, char **argv)
{
    unsigned x = 0x12345678;
    unsigned y = 0x12345678;

    printf("Product of x and y: %lx\n", (uint64_t)x * y);
    printf("High 32-bit value: %x\n", unsigned_high_prod(x, y));

    return 0;
}

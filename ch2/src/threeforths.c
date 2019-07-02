/**
 * @file    threeforths.c
 *
 * @brief   2.80
 *  for integer argument x, function threeforths computes the value
 *  of 3x/4, rounded toward zero.
 *  It should not overflow.
 *
 */
#include <stdio.h>
#include <limits.h>

#if 0
static int div4(int x, int k)
{
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));
    (is_neg || (x = x + (1 << k) - 1));

    printf("x_tmp = %d, oneforth = %d\n", x, x >> k);

    return x >> k;
}
int threeforths(int x)
{
    int div = div4(x, 2);
    // return (div << 1) + div;
    return x - div;
}
#endif
int threeforths(int x)
{
    int is_neg = x & INT_MIN;
    int f = x & ~0x03;
    int l = x &  0x03;

    int fd4 = f >> 2;
    int fd4m3 = (fd4 << 1) + fd4;  // * 3

    int lm3 = (l << 1) + l;
    int bias = (1 << 2) - 1;
    (is_neg && (lm3 += bias));
    int lm3d4 = lm3 >> 2;

    return fd4m3 + lm3d4;
}

int main(int argc, char** argv)
{
    int x;

    x = -12;
    printf("x = %d, threeforths = %d\n", x, threeforths(x));
    printf("threeforths = %f\n\n", x / 4.0 * 3.0);

    x = -7;
    printf("x = %d, threeforths = %d\n", x, threeforths(x));
    printf("threeforths = %f\n\n", x / 4.0 * 3.0);

    x = -9;
    printf("x = %d, threeforths = %d\n", x, threeforths(x));
    printf("threeforths = %f\n\n", x / 4.0 * 3.0);

    x = 11;
    printf("x = %d, threeforths = %d\n", x, threeforths(x));
    printf("threeforths = %f\n\n", x / 4.0 * 3.0);

    x = 8;
    printf("x = %d, threeforths = %d\n", x, threeforths(x));
    printf("threeforths = %f\n\n", x / 4.0 * 3.0);

    x = 7;
    printf("x = %d, threeforths = %d\n", x, threeforths(x));
    printf("threeforths = %f\n\n", x / 4.0 * 3.0);

    return 0;
}

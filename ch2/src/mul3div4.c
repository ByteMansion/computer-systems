/**
 * @file    mul3div4.c
 *
 * @brief   2.79
 *  Compute 3*x/4
 *  The computation 3*x can cause overflow
 *
 */
#include <stdio.h>
#include <limits.h>

static int divide_power2(int x, int k)
{
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));
    return x >> k;
}

int mul3div4(int x)
{
    /**
     * we can transfer product computation into left shift and addition.
     */
    int mul3 = (x << 1) + x;
    return divide_power2(mul3, 2);
}

int main(int argc, char** argv)
{
    int x;

    x = -7;
    printf("x = %d, mul3div4 = %d\n", x, mul3div4(x));
    // printf("float_mul3div4 = %f\n", x * 3.0 / 4.0);

    x = -9;
    printf("x = %d, mul3div4 = %d\n", x, mul3div4(x));
    // printf("float_mul3div4 = %f\n", x * 3.0 / 4.0);

    x = 10;
    printf("x = %d, mul3div4 = %d\n", x, mul3div4(x));
    // printf("float_mul3div4 = %f\n", x * 3.0 / 4.0);

    return 0;
}

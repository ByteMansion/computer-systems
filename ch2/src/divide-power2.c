/**
 * @file    divide-power2.c
 *
 * @brief   2.78
 *  Divide by power of 2
 *  Assume 0 <= k < w-1
 *
 */
#include <stdio.h>
#include <limits.h>

/**
 * @brief   Integer division always rounds towards zero.
 */
int divide_power2(int x, int k)
{
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));

    return x >> k;
}

int main(int argc, char** argv)
{
    int x, k;

    x = -7;
    k = 2;
    printf("x = %d, k = %d, divide power = %d\n", x, k, divide_power2(x, k));

    x = 7;
    k = 2;
    printf("x = %d, k = %d, divide power = %d\n", x, k, divide_power2(x, k));

    return 0;
}

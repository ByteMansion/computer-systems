/**
 * @file    saturating-add.c
 *
 * @brief   2.73
 *  Instead of overflowing the way normal 2's complement addition does, saturating addition
 *  returns TMax when there would be positive overflow, and TMin when there would be negative
 *  overflow. Saturating arithmetic is commonly used in programs that perform digital signal
 *  processing.
 *
 */
#include <stdio.h>
#include <limits.h>
#include <assert.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    /**
     * positive overflow, if x > 0, y > 0, but sum < 0,
     * negative overflow, if x < 0, y < 0, but sum >= 0
     */
    int pos_over = !(x & INT_MIN) && !(y & INT_MIN) &&  (sum & INT_MIN);
    int neg_over =  (x & INT_MIN) &&  (y & INT_MIN) && !(sum & INT_MIN);

    (pos_over & (sum = INT_MAX) || (neg_over && (sum = INT_MIN)));

    return sum;
}

int main(int argc, char** argv)
{
    int sum;

    sum = saturating_add(INT_MIN, -10);
    assert(sum == INT_MIN);

    sum = saturating_add(INT_MAX, 10);
    assert(sum == INT_MAX);

    return 0;
}

/**
 * @file    tsub-ok.c
 *
 * @brief   2.74
 *  Determine whether arguments can be subtracted without overflow.
 *
 * @return
 *  1: computation (x-y) does not overflow
 *  0: otherwise
 */
#include <stdio.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
    int res = 1;
    // if y == INT_MIN, the sub x-y must overflow
    (y == INT_MIN) && (res = 0);

    int sub = x - y;

    /**
     * now what we care about is x and z(-y)
     * if x > 0, z > 0, but sub < 0, positive overflow
     * if x < 0, z < 0, but sub >= 0, negative overflow
     */
    int pos_over = !(x & INT_MIN) &&  (y & INT_MIN) &&  (sub & INT_MIN);
    int neg_over =  (x & INT_MIN) && !(y & INT_MIN) && !(sub & INT_MIN);

    // printf("the sub is %d.\n", sub);

    return res && !(pos_over || neg_over);
}

int main(int argc, char** argv)
{
    int x, y;

    x = 10; y = INT_MIN;
    if(tsub_ok(x, y)) {
        printf("the sub of %d and %d does not overflow.\n", x, y);
    } else {
        printf("the sub of %d and %d does overflow.\n", x, y);
    }

    return 0;
}

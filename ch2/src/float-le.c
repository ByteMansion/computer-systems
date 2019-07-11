/**
 * @file    float-le.c
 *
 * @brief   2.84
 *  test whether the first argument is less than or equal to its second
 *
 * @return
 *  1: first argument is less than or equal to the second
 *  0: otherwise
 *
 */
#include <stdio.h>
#include <assert.h>

static unsigned f2u(float x)
{
    return *(unsigned*)(&x);
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    printf("unsigned x = 0x%x, unsigned y = 0x%x\n", ux, uy);

    /* Get the sign bit */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* give an expression using only ux, uy, sx, sy */
    return (ux<<1 == 0 && uy<<1 == 0) ||  /* whatever the sign is, +0 or -0 */
           (sx && !sy) ||  /* x <= -0, y >= +0 */
           (!sx && !sy && ux <= uy) ||  /* x >= +0, y >= +0 */
           (sx && sy && ux >= uy);  /* x <= -0, y <= -0 */
}

int main(int argc, char** argv)
{
    assert(float_le(0.0, 0.00));
    assert(float_le(-0.0, 0.0));
    assert(float_le(0.0, -0.0));
    assert(float_le(-3.2, -1.0));
    assert(float_le(7.00, 7.001));
    return 0;
}

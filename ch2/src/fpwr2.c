/**
 * @file    fpwr2.c
 * 
 * @brief   2.90
 *  Construct the IEEE single-precision representation of the result.
 *  When x is too small, your routine will return 0.0. When x is too large,
 *  it will return positive infinity. 
 *
 */

#include <stdio.h>
#include <math.h>

static float u2f(unsigned u)
{
    return *(float*)(&u);
}

float fpwr2(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    if (x < -149) {  // -126 + (-23)
        /* Too small. Return 0.0 */
        exp  = 0x0;
        frac = 0x0;
    } else if (x < -126) {  // 1 - 127
        /* Denormalized result */
        exp  = 0;
        frac = 1 << (x + 149);
    } else if (x < 128) {  // 127 + 1
        /* Normalized result */
        exp  = x + 127;
        frac = 0;
    } else {
        /* Too big. Return +oo */
        exp  = 0xff;
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}

int main(int argc, char** argv)
{
    int x;

    x = -150;
    printf("x = %d, pow(x) = %.50f\n", x, fpwr2(x));

    x = -133;
    printf("x = %d, pow(x) = %.50f\n", x, fpwr2(x));

    x = -126;
    printf("x = %d, pow(x) = %.50f\n", x, fpwr2(x));

    x = -1;
    printf("x = %d, pow(x) = %.50f\n", x, fpwr2(x));

    x = 127;
    printf("x = %d, pow(x) = %.50f\n", x, fpwr2(x));

    x = 150;
    printf("x = %d, pow(x) = %f\n", x, fpwr2(x));

    return 0;
}
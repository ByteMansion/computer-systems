/**
 * @file    float-negate.c
 *
 * @brief   2.92
 *  For floating-point number f, this function computes -f. 
 *  If f is NaN, your function should simply return f.
 *
 */

#include <stdio.h>

typedef unsigned float_bits;

static float u2f(float_bits u)
{
    return *(float*)(&u);
}
float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    
    sign = ~sign;
    if(exp == 0xFF && frac != 0) {  // special value
        return f;
    }
    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char** argv)
{
    unsigned f;

    f = 0x12345678;
    printf("f = %.50f, negate_f = %.50f \n", u2f(f), u2f(float_negate(f)));

    f = 0xF2345678;
    printf("f = %.50f, negate_f = %.50f \n", u2f(f), u2f(float_negate(f)));

    f = 0x7FA12345;
    printf("f = %.50f, negate_f = %.50f \n", u2f(f), u2f(float_negate(f)));

    f = 0x80000123;
    printf("f = %.50f, negate_f = %.50f \n", u2f(f), u2f(float_negate(f)));

    return 0;
}
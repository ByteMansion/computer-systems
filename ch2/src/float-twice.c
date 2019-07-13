/**
 * @file    float-twice.c
 * 
 * @brief   2.94
 *  For floating-point number f, this function computes 2.0 * f.
 *  If f is NaN, your function should simple return f.
 * 
 */
#include <stdio.h>

typedef unsigned float_bits;
static float u2f(unsigned u)
{
    return *(float*)&u;
}

float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if(exp == 0xFF) {  // no matter which special value, NaN or infinity
        return f;
    }

    // 2.0 * f
    exp += 1;

    return (sign << 31) | (exp << 23) | f;
}

int main(int argc, char** argv)
{
    unsigned f;

    f = 0xFF812345;  // Nan
    printf("f = %.50f,\t 2.0 * f = %.50f\n", u2f(f), u2f(float_twice(f)));

    f = 0x7F712345;  // exp = 0xFE
    printf("f = %.50f,\t 2.0 * f = %.50f\n", u2f(f), u2f(float_twice(f)));

    f = 0x80012345;  // exp = 0
    printf("f = %.50f,\t 2.0 * f = %.50f\n", u2f(f), u2f(float_twice(f)));

    f = 0x80000001;  // exp = 0, frac = 0.0...01
    printf("f = %.50f,\t 2.0 * f = %.50f\n", u2f(f), u2f(float_twice(f)));

    return 0;
}
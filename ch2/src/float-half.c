/**
 * @file    float-half.c
 * 
 * @brief   2.95
 *  For floating-point number f, this function computes 0.5 * f.
 *  If f is NaN, your function should simple return f.
 * 
 */

#include <stdio.h>

typedef unsigned float_bits;

static float u2f(unsigned u)
{
    return *(float*)(&u);
}

float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if(exp == 0xFF) {  // if f is NaN or infinity value, return f
        return f;
    }
    if(exp == 0) {  // denormalized value
        frac = frac >> 1;
    } else if(exp == 1) {  // normalized value
        exp = 0;
        frac = (frac >> 1) | 0x400000;;
    } else {
        exp -= 1;
    }

    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char** argv)
{
    unsigned f;

    f = 0x7F812345;  // exp = OxFF, frac != 0
    printf("f = %.50f,\t 0.5*f = %.50f\n", u2f(f), u2f(float_half(f)));
    
    f = 0x7F800000;  // exp = OxFF, frac = 0
    printf("f = %.50f,\t 0.5*f = %.50f\n", u2f(f), u2f(float_half(f)));

    f = 0x80012345;  // exp = 0
    printf("f = %.50f,\t 0.5*f = %.50f\n", u2f(f), u2f(float_half(f)));

    f = 0x00800005;  // exp = 1
    printf("f = %.50f,\t 0.5*f = %.50f\n", u2f(f), u2f(float_half(f)));

    return 0;
}
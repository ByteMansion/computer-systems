/**
 * @file    float-absval.c
 * 
 * @brief   2.93
 *  For floating-point number f, this function computes |f|.
 *  If f is NaN, your function should simply return f.
 * 
 */

 #include <stdio.h>

 typedef unsigned float_bits;
static float u2f(float_bits u)
{
    return *(float*)&u;
}

float_bits float_absval(float_bits f)
{
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if(exp == 0xFF && frac != 0) {  // NaN
        return f;
    }

    return (exp << 23) | frac;
}

int main(int argc, char** argv)
{
    unsigned f;

    f = 0x80123456;
    printf("f = %.50f,\t |f| = %.50f\n", u2f(f), u2f(float_absval(f)));
    
    f = 0x85123456;
    printf("f = %.50f,\t |f| = %.50f\n", u2f(f), u2f(float_absval(f)));

    f = 0x05123456;
    printf("f = %.50f,\t |f| = %.50f\n", u2f(f), u2f(float_absval(f)));

    f = 0xFFF12345;
    printf("f = %.50f,\t |f| = %.50f\n", u2f(f), u2f(float_absval(f)));

    return 0;
}
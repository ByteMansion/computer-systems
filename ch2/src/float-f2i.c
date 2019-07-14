/**
 * @file    float-f2i.c
 * 
 * @brief   2.96
 *  For floating-point number f, this function conputes (int)f.
 *  Your function should round toward zero. If f cannot be represented as an
 *  integer(e.g. it is out of range, or it is NaN), then the function should
 *  return 0x80000000.
 * 
 */

#include <stdio.h>

typedef unsigned float_bits;

static float u2f(unsigned u)
{
    return *(float*)&u;
}

int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    int val;
    unsigned E;
    unsigned M;

    // -1 < value < 1 
    if(exp < 127) {  // Bias = 0x7F
        return 0;
    } else if( exp >= 127 + 31) {  // exceed integer limit
        return 0x80000000;
    } else {
        E = exp - 127;
        // M = frac | 0x800000;
        if(E > 23) {
            val = (1 << E) | (frac << (E - 23));
        } else {  // round toward 0
            val = (1 << E) | (frac >> (23 - E));
        }
    }

    return sign ? -val : val;
}

int main(int argc, char** argv)
{
    unsigned f;

    f = 0x80712345;  // sign = 1, exp = 0, frac != 0
    printf("f = %.50f, f2i = %d\n", u2f(f), float_f2i(f));

    f = 0x43812345;  // sign = 0, exp = 128+7
    printf("f = %.50f, f2i = %d\n", u2f(f), float_f2i(f));

    f = 0xC3812345;  // sign = 1, exp = 128+7
    printf("f = %.50f, f2i = %d\n", u2f(f), float_f2i(f));

    f = 0xF0001234;  // sign = 1, exp = 0xE0, frac != 0
    printf("f = %.50f, f2i = %d\n", u2f(f), float_f2i(f));   
    
    f = ((127+31) << 23) | 0x7FFFF;  // E = 31, INT_MIN
    printf("f = %.50f, f2i = %d\n", u2f(f), float_f2i(f)); 
    
    f = ((127 + 30) << 23) | 0x7FFFF;  // E = 30
    printf("f = %.50f, f2i = %d\n", u2f(f), float_f2i(f));    
    

    return 0;
}
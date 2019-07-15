/**
 * @file    float-i2f.c
 * 
 * @brief   2.97
 *  For argument i, this function computes the bit-level representation
 *  of (float)i.
 * 
 */

#include <stdio.h>

typedef unsigned float_bits;

static float u2f(unsigned u)
{
    return *(float*)&u;
}
static unsigned leftmost_one(unsigned i)
{
    i |= i >> 1;
    i |= i >> 2;
    i |= i >> 4;
    i |= i >> 8;
    i |= i >> 16;

    return (i >> 1) + (i && 1);
}


float_bits float_i2f(int i)
{
    unsigned sign  = 0;
    unsigned exp   = 0;
    unsigned frac  = 0;
    if (i == 0) {
        return (sign << 31) | (exp << 23) | frac;
    }

    sign = i >> 31;

    // get the left-most 1 in i
    unsigned nosign = i ^ (sign << 31);
    if (sign)
    {
        nosign = (1 << 31) - nosign;
    }
    

    // get leftmost one and the length from the first one to the end
    unsigned leftmost = leftmost_one(nosign);
    unsigned length = 31;
    while (!((1 << length) & leftmost))
    {
        length -= 1;
    }
    
    frac = nosign - leftmost;  // get all ones except for the leftmost
    if (length > 23) {
        frac = (frac >> (length - 23)) & 0x7FFFFF;
    } else {
        frac = (frac << (23 - length)) & 0x7FFFFF;
    }
    
    return (sign << 31) | ((127+length) << 23) | frac;
}

int main(int argc, char** argv)
{
    int i;

    i = 0x12345678;  // positive
    printf("i = %d, f = %f\n", i, u2f(float_i2f(i)));

    i = 0x8F123456;  // negative
    printf("i = %d, f = %f\n", i, u2f(float_i2f(i)));

    i = 0x8FFFFF00;  // negative, small integer
    printf("i = %d, f = %f\n", i, u2f(float_i2f(i)));

    i = 0x00000FFF;  // positive, small integer
    printf("i = %d, f = %f\n", i, u2f(float_i2f(i)));

    return 0;
}
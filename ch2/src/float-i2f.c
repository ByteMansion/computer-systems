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
    unsigned sign = i >> 31;

    // get the left-most 1 in i
    unsigned nosign = i ^ (sign << 31);
    unsigned leftmost = leftmost_one(nosign);
    unsigned frac = ((nosign - leftmost) ^ nosign);

}

int main(int argc, char** argv)
{


    return 0;
}
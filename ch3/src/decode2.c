/**
 * @file    decode2.c
 * 
 * @brief   3.58
 *  Generate c code according to as code
 * 
 */
#include <stdio.h>

long decode2(long x, long y, long z)
{
    long v1 = y - z;
    long v2 = x * v1;
    v1 = v1 << 63;
    v1  = v1 >> 63;
    return v2 ^ v1;
}

int main(int argc, char** argv)
{
    long x, y, z;

    x = 1;
    y = -2;
    z = 3;
    printf("x = %ld, y = %ld, z = %ld, decode = %ld\n", x, y, z, decode2(x, y, z));

    return 0;
}
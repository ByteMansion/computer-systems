/**
 * @file    switch-prob.c
 * 
 * @brief   3.63
 * 
 */

#include <stdio.h>

long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 0+0x3c:
    // case 1+0x3c:  /* we only have 6 entries in jump table */
    case 2+0x3c:
        result = 8 * x;
        break;
    case 3+0x3c:
        result = x >> 3;
        break;
    case 4+0x3c:
        x= (x << 4) - x;
    case 5+0x3c:
        x *= x;
    default:
        result = x + 0x4b;
        break;
    }
    return result;
}

int main(int argc, char** argv)
{
    for (long n = 0x3c; n < 6+0x3c; n++) {
        printf("n = %ld, result = %ld\n", n, switch_prob(0x1234, n));
    }
    
    return 0;
}
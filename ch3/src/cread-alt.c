/**
 * @file    cread-alt.c
 * 
 * @brief   3.61
 *  Implemente conditional move instruction using C function.
 *  This function cannot be compiled to jump instructions.
 * 
 */

#include <stdio.h>

/**
 * Actually, I compiled these two implementations and then use objdump command
 * to generate their assembly code. They have absolutely same assembly code.
 * These code also works well.
 */
long cread(long *xp)
{
    return (xp ? *xp : 0);
}

long cread_alt(long *xp)
{
    return (!xp ? 0 : *xp);
}

int main(int argc, char** argv)
{
    long x;

    printf("xp = %ld\n", cread(&x));
    printf("xp = %ld\n", cread_alt(&x));

    printf("xp = %ld\n", cread(NULL));
    printf("xp = %ld\n", cread(NULL));


    return 0;
}
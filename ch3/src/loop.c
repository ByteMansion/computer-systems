/**
 * @file    loop.c
 * 
 * @brief   2.60
 *  
 */

#if 0
loop:
    movl    %esi, %ecx
    movl    $1, %edx
    movl    $0, %eax
    jmp     .L2
.L3:
    movq    %rdi, %r8
    andq    %rdx, %r8
    orq     %r8, %rax
    salq    %cl, %rdx
.L2:
    testq   %rdx, %rdx
    jne     .L3
    rep; ret
#endif

#include <stdio.h>

long loop(long x, int n)
{
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask = mask << n)
    {
        result |= x & mask;
    }

    return result;
}

int main(int argc, char** argv)
{
    long x;
    int n;

    x = 0x123456789;
    n = 2;
    printf("x = %lx, n = %d, loop = %lx\n", x, n, loop(x, n));

    return 0;
}
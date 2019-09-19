/**
 * @file    5.17.c
 * 
 * @brief   solution to problem 5.17
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/* Basic implementation of memset */
void *basic_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    unsigned char *schar = s;
    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }
    
    return s;
}

/* Efficient implementation of memset */
void *efficient_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    size_t step = sizeof(unsigned long);

    // pad pre-aligned bytes
    unsigned char *schar = s;
    size_t start = (size_t)schar % step;
    while (cnt < start) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    // pad memory in words
    size_t wordCnt = (n - start) / step;
    unsigned long *slong = (unsigned long *) schar;
    for (size_t i = 0; i < wordCnt; i++) {
        *slong++ = (unsigned long) c;
    }
    
    // pad remained bytes
    size_t remainCnt = (n - start) % step;
    schar = (unsigned char *) slong;
    for (cnt = 0; cnt < remainCnt; cnt++) {
        *schar++ = (unsigned char) c;
    }
    
    return s;
}

int main() 
{
    size_t memSize = 0x1234;

    void *basicMem = malloc(memSize);
    void *efficMem = malloc(memSize);
    int padNum = 0xAA;

    basic_memset(basicMem, padNum, memSize);
    efficient_memset(efficMem, padNum, memSize);

    free(basicMem);
    free(efficMem);

    return 0;
}
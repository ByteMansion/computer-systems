/**
 * @file    5.18.c
 * 
 * @brief   Solution to problem 5.18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>

double polyOpt(double a[], double x, long degree)
{
    long   i;
    double xpwr = x;
    double result0 = a[0];
    double result1 = 0;
    double result2 = 0;
    double result3 = 0;
    double result4 = 0;
    double result5 = 0;
    for (i = 1; i <= degree && i+5 <= degree; i += 6) {
        result0 += a[i] * xpwr;
        xpwr *= x;
        result1 += a[i+1] * xpwr;
        xpwr *= x;
        result2 += a[i+2] * xpwr;
        xpwr *= x;
        result3 += a[i+3] * xpwr;
        xpwr *= x;
        result4 += a[i+4] * xpwr;
        xpwr *= x;
        result5 += a[i+5] * xpwr;
        xpwr *= x;
    }

    for (; i <= degree; i++) {
        result0 += a[i] * xpwr;
        xpwr *= x;
    }
    
    return (result0 + result1 + result2 + result3 + result4 + result5);
}
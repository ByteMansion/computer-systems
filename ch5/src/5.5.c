/**
 * @file    5.5.c
 * 
 * @brief   Polynomial evaluation
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>

double poly(double a[], double x, long degree)
{
    long   i;
    double result = a[0];
    double xpwr = x;  // Equals x^i at start of loop
    for ( i = 1; i <= degree; i++)
    {
        result += a[i] * xpwr;
        xpwr *= x;
    }

    return result;
}

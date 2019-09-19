/**
 * @file    5.6.c
 * 
 * @brief   Hornor's method
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>

double polyh(double a[], double x, long degree)
{
    long  i;
    double result = a[degree];
    for ( i = degree - 1; i >= 0; i--)
    {
        result = a[i] + x * result;
    }
    
    return result;
}
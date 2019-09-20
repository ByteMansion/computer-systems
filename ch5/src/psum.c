/**
 * @file    psum.c
 * 
 * @brief   Compute prefix sum of vector
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "psum.h"

void psum1(float a[], float p[], long n)
{
    long i;
    p[0] = a[0];
    for ( i = 0; i < n; i++) {
        p[i] = p[i-1] + a[i];
    }
    
}

void psum2(float a[], float p[], long n)
{
    long i;
    p[0] = a[0];
    for (i = 1; i < n-1; i += 2) {
        float mid_val = p[i-1] + a[i];
        p[i] = mid_val;
        p[i+1] = mid_val + a[i+1];
    }
    // For even n, finish remaining element
    if (i < n) {
        p[i] = p[i-1] + a[i];
    }
}

// CPE 3.0
void psum1a(float a[], float p[], long n)
{
    long i;
    // last_val holds p[i-1]; val holds p[i]
    float last_val, val;
    last_val = p[0] = a[0];
    for (i = 1; i < n; i++) {
        val      = last_val + a[i];
        p[i]     = val;
        last_val = val;
    }
}

void psum3(float a[], float p[], long n)
{
    long i;
    float last_val, val;
    float result0, result1, result2, result3;

    last_val = 0;
    for (i = 0; i < n && i+3 < n; i += 4) {
        result0 = last_val + a[i];
        result1 = result0  + a[i+1];
        result2 = result1  + a[i+2];
        result3 = result2  + a[i+3];

        p[i]   = result0;
        p[i+1] = result1;
        p[i+2] = result2;
        p[i+3] = result3;

        last_val += a[i] + a[i+1] + a[i+2] + a[i+3];
    }

    for (; i < n; i++) {
        val      = last_val + a[i];
        p[i]     = val;
        last_val = val;
    }
}
/**
 * @file    poly.c
 * 
 * @brief   Verify the correctness of polynomial evaluation
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "poly.h"

int main() 
{
    double a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    long degree = 8;
    double base = 2.0;
    double result;
    
    printf("Polynomial evaluation\n\n");
    
    result = poly(a, base, degree);
    printf("Original method: %lf\n", result);

    result = polyHornor(a, base, degree);
    printf("Hornor's method: %lf\n", result);

    result = polyOpt(a, base, degree);
    printf("Optimized method: %lf\n", result);

    return 0;
}
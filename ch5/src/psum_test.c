/**
 * @file    psum_test.c
 * 
 * @brief 
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "psum.h"

static void printVec(float a[], long n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%.3f \t", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    float a[5] = {1.0, 2.4, 3.1, 5.2, 9.2};
    float p[5] = {0, 0, 0, 0, 0};
/*
    psum1(a, p, 5);
    printVec(p, 5);

    psum2(a, p, 5);
    printVec(p, 5);

    psum1a(a, p, 5);
    printVec(p, 5);
*/
    psum3(a, p, 5);
    printVec(p, 5);

    return 0;
}

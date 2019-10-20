/**
 * @file   transpose.cpp
 * @author Changrui
 * @brief  transpose a matrix
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>

#define BLOCK 8
#define SIZE 1024
#define N 27

void transpose(int *dst, int *src, int dim)
{
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            dst[j*dim + i] = src[i*dim + j];
        }
    }
}

void transposeOpt(int *dst, int *src, int dim)
{
    int i, j;
    int row, col;
    
    for (i = 0; i < N-BLOCK; i += BLOCK) {
        for (j = 0; j < N-BLOCK; j += BLOCK) {
            for (row = i; row < i+BLOCK; i++) {
                for (col = j; col < j+BLOCK; j++) {
                    dst[col*N+row] = src[row*N+col];
                }
            }
        }
    }

    // handle remained element after n blocks
    int offset = i;
    for (i = offset; i < N; i++) {
        for (j = 0; j < offset; j += BLOCK) {
            for (col = j; col < j+BLOCK; col++) {  // in remained elements, still use cache block to optimize 
                dst[col*N+i] = src[i*N+col];
            }
        }
    }

    // handle remained elements less than block size
    for (i = offset; i < N; i++) {
        for (j = offset; j < N; j++) {
            dst[j*N+i] = src[i*N+j];
        }
    } 
}

int main()
{

    return 0;
}
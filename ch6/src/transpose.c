/**
 * @file   transpose.cpp
 * @author Changrui
 * @brief  transpose a matrix
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define     BLOCK      16
#define     N          2217

const int  CS_STATUS_FALSE = 1024;
const int  CS_STATUS_TRUE  = 1;

void transpose(int *dst, int *src, int dim)
{
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            dst[j*dim + i] = src[i*dim + j];
        }
    }
}

/**
 * @brief assume a 5*5 matrix, cache block size is 3*sizeof(int)
 * 
 *        | x x x x x |
 *        | x x x x x |
 *        | x x x x x |
 *        | x x x x x |
 *        | x x x x x |
 * 
 * @param dst pointer to destination matrix
 * @param src pointer to source matrix
 * @param dim 
 */
void transposeOpt(int *dst, int *src, int dim)
{
    int i, j;
    int row, col;

    // transpose all BLOCK unit matrix
    for (i = 0; i <  dim-BLOCK; i += BLOCK) {
        for (j = 0; j < dim-BLOCK; j += BLOCK) {
            for (row = i; row < i+BLOCK; row++) {
                for (col = j; col < j+BLOCK; col++) {
                    dst[col*dim+row] = src[row*dim+col];
                }
            }
        }
    }

    // handle remained element after n blocks
    int offset = i;
    for (i = offset; i < dim; i++) {
        for (j = 0; j < offset; j += BLOCK) {
            // in remained elements, still use cache block to optimize
            for (col = j; col < j+BLOCK; col++) { 
                dst[col*dim+i] = src[i*dim+col];
            }
        }
    }

    // handle remained elements less than block size
    for (i = offset; i < dim; i++) {
        for (j = offset; j < dim; j++) {
            dst[j*dim+i] = src[i*dim+j];
        }
    } 
}

int randomize(int *src, int size)
{
    int rand  = open("/dev/urandom", O_RDONLY);
    if (-1 == rand) {
        printf("Open file descriptor fails!\n");
        exit(CS_STATUS_FALSE);
    }
    int count = read(rand, src, size);
    assert(count == size);

    close(rand);
    return CS_STATUS_TRUE;
}

void verify_result(int *dst, int *src, int size)
{
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            assert(dst[j*size+i] == src[i*size+j]);
        }
    }

}

int main()
{
    // initialize source matrix
    int mem_size = sizeof(int) * N * N;
    int *src = (int*)malloc(mem_size);
    if (NULL == src) {
        printf("Allocate memory fails!\n");
        exit(CS_STATUS_FALSE);
    }
    int status = randomize(src, mem_size);
    assert(CS_STATUS_TRUE == status);

    int *dst = (int*)malloc(sizeof(int)*N*N);
    if (NULL == dst) {
        printf("Allocate memory fails!\n");
        exit(CS_STATUS_FALSE);
    }

    printf("Before Optimizing\n");
    transpose(dst, src, N);
    verify_result(dst, src, N); 

    printf("Optimizing\n");
    transposeOpt(src, dst, N);
    verify_result(src, dst, N);

    // release memory
    free(src);
    free(dst);

    return 0;
}
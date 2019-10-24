/**
 * @file    col-convert.c
 * 
 * @brief   Convert a directed graph into an undirected graph
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  BLOCK  16
#define  N      211

void col_convert(int *G, int dim)
{
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            G[j*dim + i] = G[j*dim + j];
        }
    }
}

void opt_col_convert(int *G, int dim)
{
    int i, j;
    int col, row;
    int tmp;

    for (i = 0; i < dim-BLOCK; i += BLOCK) {
        for (j = i; j < dim-BLOCK; j += BLOCK) {
            for (row = i; row < i+BLOCK; row++) {
                for (col = j; col < j+BLOCK; col++) {
                    tmp = G[col*dim + row] || G[row*dim + col];
                    G[col*dim + row] = tmp;
                    G[row*dim + col] = tmp;
                }
            }
        }
    }

    int offset = i;
    for (i = offset; i < dim; i++) {
        for (j = 0; j < offset; j += BLOCK) {
            // in remained elements, still use cache block to optimize
            for (col = j; col < j+BLOCK; col++) { 
                tmp = G[col*dim + i] || G[i*dim + col];
                G[col*dim + i] = tmp;
                G[i*dim + col] = tmp;
            }
        }
    }

    // handle remained elements less than block size
    for (i = offset; i < dim; i++) {
        for (j = i; j < dim; j++) {
            tmp = G[j*dim + i] || G[i*dim + j];
            G[j*dim + i] = tmp;
            G[i*dim + j] = tmp;
        }
    } 

}

void init_matrix(int *matrix, int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i*size + j] = rand() % 2;
        }
    }
}

int main()
{
    int *G = (int *)malloc(sizeof(int) * N * N);
    if (NULL == G) {
        printf("Insufficient resource!\n");
        exit(1);
    }

    init_matrix(G, N);

    printf("Before optimizing\n");
    col_convert(G, N);

    printf("Optimizing\n");
    opt_col_convert(G, N);

    return 0;
}
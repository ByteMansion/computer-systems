/*
 * @file    utils.c
 *
 * @brief   utilities used in other files
 *
 */
#include "util.h"

void print_array(long* data, long count)
{
    long i;
    for(int i = 0; i < count; i++)
        printf("%ld\t", *(data+i));
    printf("\n");
}
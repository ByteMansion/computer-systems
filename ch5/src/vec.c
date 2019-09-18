/**
 * @file    vec.c
 * @brief   util implementation
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "vec.h"

#include <stdio.h>

/* Create vector of specified length */
vec_ptr new_vec(long len)
{
    /* Allocate header structure */
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    data_t *data = NULL;
    if (!result) {
        return NULL;
    }
    result->len = len;
    /* Allocate array */
    if (len > 0) {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free((void *) result);
            return NULL; /* Couldn't allocate storage */
        }
    }
    /* Data will either be NULL or allocated array */
    result->data = data;
    return result;
}

/*
 * Retrieve vector element and store at dest.
 * Return 0 (out of bounds) or 1 (successful) 
 */
int get_vec_element(vec_ptr v, long index, data_t *dest)
{
    if (index < 0 || index >= v->len) {
        return 0;
    }
    *dest = v->data[index];
    return 1;
}

/*
 * Return length of vector
 */
long vec_length(vec_ptr v)
{
    return v->len;
}

data_t *get_vec_start(vec_ptr v)
{
    return v->data;
}
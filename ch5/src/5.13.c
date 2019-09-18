/**
 * @file    5.13.c
 *
 * @brief   source code of problem 5.13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "vec.h"

/* Inner product. Accumulate in temporatory. */
void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
    long i;
    long length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t) 0;

    for (i = 0; i < length; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}

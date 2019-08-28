/**
 * @file    bubble-b.c
 * 
 * @brief   4.47
 *  Implement a bubble sort procedure.
 * 
 */

#include "util.h"

void bubble_b(long* data, long count)
{
    long *i, *last; 
    for(last = data+count-1; last > data; last--) {
        for(i = data; i < last; i++) {
            if(*(i+1) < *i) {
                long t = *(i+1);
                *(i+1) = *i;
                *i = t;
            }
        }
    }
}

int main(int argc, char** argv)
{
    long data[10] = {0, 1, 4, 2, 5, 9, 8, 3, 7, 6};

    printf("Unsorted array:\t");
    print_array(data, 10);

    bubble_b(data, 10);

    printf("Sorted array:\t");
    print_array(data, 10);

    return 0;
}
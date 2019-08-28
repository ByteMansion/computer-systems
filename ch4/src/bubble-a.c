/**
 * @file    bubble-a.c
 *
 * @brief   Implement bubble sort using array referencing
 *
 */

#include "util.h"

void bubble_a(long *data, long count)
{
    long i, last;
    for(last = count-1; last > 0; last--) {
        for(i = 0; i < last; i++) {
            if(data[i+1] < data[i]) {
                long t = data[i+1];
                data[i+1] = data[i];
                data[i] = t;
            }
        }
    }
}

int main(int argc, char** argv)
{
    long data[10] = {0, 1, 4, 2, 5, 9, 8, 3, 7, 6};

    printf("Unsorted array:\t");
    print_array(data, 10);

    bubble_a(data, 10);

    printf("Sorted array:\t");
    print_array(data, 10);

    return 0;
}
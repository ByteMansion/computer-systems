/**
 * @file    calloc.c
 *
 * @brief   2.76
 *  void* calloc(size_t nmemb, size_t size);
 *  The calloc function allocates memory for an array of nmemb elements
 *  of size bytes each. The memory is set to zero. If nmemb or size is zero,
 *  then calloc return NULL.
 *
 *  Write an implementation of calloc that performs the allocation by a call
 *  to malloc and sets the memory to zero via memset. Your code should not
 *  have any vulnerabilities due to arithmetic overflow, and it should work
 *  correctly regardless of the number of bits used to represent data of type
 *  size_t.
 *
 *  void *malloc(size_t size);
 *  void *memset(void *s, int c, size_t n);
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>

void* self_calloc(size_t nmemb, size_t size)
{
    if(nmemb == 0 || size == 0) {
        return NULL;
    }
    size_t len = nmemb * size;
    if(nmemb == len / size) {
        void* ptr = malloc(len);
        if(ptr != NULL) {
            memset(ptr, 0, len);
        }
        return ptr;
    }

    return NULL;

}

int main(int argc, char** argv)
{
    size_t nmemb, size;
    void* ptr;

    ptr = self_calloc(100, sizeof(int));
    if(ptr != NULL) {
        printf("Allocate space successfully!\n");
        free(ptr);
    }

    nmemb = SIZE_MAX;
    size = sizeof(int);
    ptr = self_calloc(nmemb, size);
    if(ptr != NULL) {
        printf("Allocate space successfully!\n");
        free(ptr);
    } else {
        printf("Cannot allocate!\n");
    }

    nmemb = UINT_MAX;
    size = sizeof(int);
    ptr = self_calloc(nmemb, size);
    if(ptr != NULL) {
        printf("Allocate space successfully!\n");
        free(ptr);
    } else {
        printf("Cannot allocate!\n");
    }

    return 0;
}

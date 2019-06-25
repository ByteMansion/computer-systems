/**
 * @file    is-little-endian.c
 *
 * @brief   2.58
 *  get if the process is little endian
 *
 * @return
 *  1: the process is little endian
 *  0: the process is big endian
 *
 */
#include <stdio.h>

#define sizeof(int) INTLEN

typedef unsigned char *byte_pointer;

int is_little_endian(void)
{
    // little endian: low bits saved in low address
    int test_num = 0xFF;
    byte_pointer pNum = (byte_pointer)&test_num;
    if(pNum[0] == 0xFF) {
      return 1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    if(is_little_endian()) {
        printf("Little endian!\n");
    } else {
        printf("Big endian!\n");
    }

    return 0;
}

/**
 * @file    replace-byte.c
 *
 * @brief   2.60
 *  replace ith byte in para x with para b
 *
 *  x: unsigned integer
 *  b: unsigned char
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define UINTLEN sizeof(unsigned)

unsigned replace_byte(unsigned x, unsigned char b, int i)
{
    if(i >= 0) {
        i %= UINTLEN;
    } else {
        i = UINTLEN - abs(i) % UINTLEN;
    }

    size_t offset = i << 3;
    unsigned mask = 0xff << offset;
    return (((x & mask) ^ x) | (b << offset));
}
void show_bytes(unsigned char *nums)
{
    for(int i = 0; i < UINTLEN; ++i) {
        printf("%.2x", nums[i]);
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    unsigned x = 0x12345678;
    unsigned result;

    for(int i = -10; i < 10; ++i) {
        result = replace_byte(x, 0xab, i);

        show_bytes((unsigned char*)&result);
    }

    return 0;
}

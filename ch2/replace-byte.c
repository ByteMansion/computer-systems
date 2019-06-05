/**
 * @brief   CS2.60
 *  replace ith byte in para x with para b
 *
 */
#include <stdio.h>
#include <stdlib.h>

unsigned replace_byte(unsigned x, unsigned char b, int i)
{
    int limit = sizeof(unsigned);
    if(i >= 0) {
        i %= limit;
    } else {
        i = limit - abs(i) % limit;
    }

    unsigned or = 0xff << (i * 8);
    return ((x & or) ^ x) | (b << (i * 8));
}
void show_bytes(unsigned char *nums)
{
    for(size_t i = 0; i < sizeof(unsigned); ++i) {
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

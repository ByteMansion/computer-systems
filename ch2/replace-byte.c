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

    unsigned xl = x<<((limit-i)<<3);
    unsigned xh = x>>((i+1)<<3);
    return (b<<(i<<3))|(xh<<((i+1)<<3))|(xl>>((limit-i)<<3));
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
    unsigned char b = 0xAB;
    x = replace_byte(x, b, 2);
    show_bytes((unsigned char*)&x);

    return 0;
}

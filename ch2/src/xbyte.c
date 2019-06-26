/**
 * @file   xbyte.c
 *
 * @brief   2.71
 *  Extract the designated byte and sign extend it to be a 32-bit int.
 *
 */
#include <stdio.h>

typedef unsigned packed_t;
#if 0
/* the following code failed attempt at xbyte */
int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xff;
}
#endif

int correct_xbyte(packed_t word, int bytenum)
{
    int x = sizeof(int);
    int left_shift = (x - 1 - bytenum) << 3;
    int right_shift = (x - 1) << 3;

    return ((int)word << left_shift) >> right_shift;
}

int main(int argc, char** argv)
{
    // packed_t word = 0xAABBCCDD;
    packed_t word = 0x12345678;
    for(int i = 0; i < 4; ++i) {
        printf("extract %dth byte and extend to 0x%x\n", i, correct_xbyte(word, i));
    }

    return 0;
}

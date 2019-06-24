/**
 * @file    int-size-is-32.c
 *
 * @brief   2.67
 *  If the right operand of left shift is greater than or equal to the width of
 *  promoted left operand, the behavior is undefined.
 *
 * @return
 *  1: run on a machine for which an int is 32 bits
 *  0: otherwise
 *
 */
#include <stdio.h>

#if 0
/* the following code does not run properly on some machine */
int bad_int_size_is_32()
{
    /* set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;

    /* shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;

    /*
     * set_msb is nonzero whrn word size >= 32
     * beyond_msb is zero when word size >= 32
     */
    return set_msb && !beyond_msb;
}
#endif

/* the following code can run properly on any 32-bit or beyond machine */
int correct_int_size_is_32()
{
    int set_msb    = 1 << 31;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

/* the following code can run properly on any 16-bit or beyond machine */
int int_size_is_16()
{
    int set_msb    = 1 << 15;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int main(int argc, char **argv)
{
    printf("int type is %lu bits.\n", sizeof(int) << 3);

    if(correct_int_size_is_32()) {
        printf("int size is 32 bits.\n");
    } else {
        printf("int size is not 32 bits.\n");
    }

    return 0;
}

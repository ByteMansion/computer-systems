/**
 * @brief   CS 2.62
 *  the key to this problem is to convert signed integer to unsigned.
 *
 * @return
 *  1: arithmetic shift on the machine
 *  0: logic shift on the machine
 *
 * @note
 *  if the integer is 0, we cannot know whether the shift is arithmetic.
 */
#include <stdio.h>

int int_shifts_are_arithmetic(void)
{
    int num = -1;
    return !(num ^ (num >> 1));  // if it is arithmetic shift, xor gets 0
}

int main(int argc, char **argv)
{
    if(int_shifts_are_arithmetic()) {
        printf("Arithmetic shift!\n");
    } else {
        printf("Logical shift!\n");
    }

    return 0;
}

/**
 * @brief   CS2.58
 *  get if the process is little endian
 * 
 * @return
 *  1: the process is little endian
 *  0: the process is big endian
 *
 * @note
 *  if the number is 0 or 0.0, we cannot know whether
 *  the process is little endian or big endian.
 */
#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian(byte_pointer nums,
                     byte_pointer pNums,
                     size_t len)
{
    // low bits locate in low address
    for(size_t i = 0; i < len; ++i) {
        // if the byte number sequence is same as pointer number
        // sequence, return false
        if(nums[i] != pNums[i]) {
            return 0;
        }
    }

    return 1;
}
static void int_is_little_endian_init(int x, byte_pointer nums)
{
    for(size_t i = 0; i < sizeof(int); ++i) {
        nums[i] = (x>>(i * 8)) & 0xFF;
    }
}
int main(int argc, char **argv)
{
    int x = 1234;
    unsigned char nums[sizeof(int)];
    int_is_little_endian_init(x,nums);
    if(is_little_endian(nums, (byte_pointer)&x, sizeof(int))) {
        printf("Little endian!\n");
    } else {
        printf("Big endian!\n");
    }

    return 0;
}

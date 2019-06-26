/**
 * @file    copy-int.c
 *
 * @brief   2.72
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_int(int val, void* buf, int maxbytes)
{
    if(maxbytes >= (int)sizeof(val)) {
        memcpy(buf, (void*)&val, sizeof(val));
    }
}

int main(int argc, char** argv)
{
    int maxbytes = sizeof(int) * 10;
    void* buf = malloc(maxbytes);
    int val;

    val = 0x12345678;
    copy_int(val, buf, maxbytes);
    printf("original number: %x, copied number: %x\n", val, *(int*)buf);

    val = 0xABABCD;
    copy_int(val, buf, maxbytes);
    printf("original number: %x, copied number: %x\n", val,  *(int*)buf);

    free(buf);

    return 0;
}

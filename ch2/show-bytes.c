/**
 * @brief CS 2.55, 2.56
 *  Little endian and big endian
 *
 */
#include <stdio.h>
#include <limits.h>

typedef unsigned char *byte_pointer;

static void show_bytes(byte_pointer num, size_t xLen)
{
    for(size_t i = 0; i < xLen; ++i) {
        printf("%.2x", num[i]);
    }
    printf("\n");
}

void show_short(short x)
{
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_long(long x)
{
    show_bytes((byte_pointer)&x, sizeof(long));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_double(double x)
{
    show_bytes((byte_pointer)&x, sizeof(double));
}

int main(int argc, char **argv)
{
    int nShort = 1234;
    show_short(nShort);

    int nInt = 12345;
    show_int(nInt);

    long nLong = 123467;
    show_long(nLong);

    float nFloat = 12345.0;
    show_float(nFloat);

    double nDouble = 1234567.0;
    show_double(nDouble);

    return 0;
}

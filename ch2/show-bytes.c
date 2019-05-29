#include <stdio.h>

typedef unsigned char *byte_pointer;

static void show_bytes(byte_pointer num, size_t xLen)
{
    for(size_t i = 0; i < xLen; ++i) {
        printf("%.2x", num[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes(&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes(&x, sizeof(float));
}

void show_double(double x)
{
    show_double(&x, sizeof(double));
}

int main(int argc, char **argv)
{
    int nInt = 0x1234;
    show_int(nInt);

    float nFloat = 1.0 * 1234;
    show_float(nFloat);

    double nDouble = 10.0 * 1234;
    show_double(nDouble);

    return 0;
}

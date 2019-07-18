/**
 * @file    good-echo.c
 * 
 * @brief   3.71
 * 
 */
#include <stdio.h>

#define SIZE 8

void good_echo()
{
    char buf[SIZE];
    while (1)
    {
        char* pBuf = fgets(buf, SIZE, stdin);
        if (pBuf == NULL) {
            break;
        }
        printf("%s", buf);
    }
}

int main(int argc, char** argv)
{
    good_echo();
    printf("----End----\n");

    return 0;
}
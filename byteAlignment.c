#include <stdio.h>

int byte;
int byte_alignment;
int main(int argc, char * argv[])
{

    char test = 0;

    byte = 4;
    printf("size: %d bytes\n", sizeof(test));
    byte_alignment = sizeof(test) % byte ? ((sizeof(test) + byte) & ~(byte - 1)) : sizeof(test);
    printf("byte alignment: %d\n", byte_alignment);

    byte = 8;
    printf("size: %d bytes\n", sizeof(test));
    byte_alignment = sizeof(test) % byte ? ((sizeof(test) + byte) & ~(byte - 1)) : sizeof(test);
    printf("byte alignment: %d\n", byte_alignment);

    byte = 16;
    printf("size: %d bytes\n", sizeof(test));
    byte_alignment = sizeof(test) % byte ? ((sizeof(test) + byte) & ~(byte - 1)) : sizeof(test);
    printf("byte alignment: %d\n", byte_alignment);

    byte = 32;
    printf("size: %d bytes\n", sizeof(test));
    byte_alignment = sizeof(test) % byte ? ((sizeof(test) + byte) & ~(byte - 1)) : sizeof(test);
    printf("byte alignment: %d\n", byte_alignment);

    byte = 64;
    printf("size: %d bytes\n", sizeof(test));
    byte_alignment = sizeof(test) % byte ? ((sizeof(test) + byte) & ~(byte - 1)) : sizeof(test);
    printf("byte alignment: %d\n", byte_alignment);

    return 0;
}
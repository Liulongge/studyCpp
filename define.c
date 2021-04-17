#include <stdio.h>

#define TEST1
#define TEST5 1
int main()
{

#if defined(TEST1)
    printf("defined(TEST1)\n");
#endif

#if defined(TEST1) || defined(TEST2)
    printf("defined(TEST1) || defined(TEST2)\n");
#endif

#if defined(TEST1) && defined(TEST2)
    printf("Hello World\n");
#endif

#ifdef TEST1
    printf("#ifdef TEST1\n");
#endif

#ifndef TEST2
    printf("#ifndef TEST2\n");
#else
    printf("#ifndef TEST2 else\n");
#endif

#if TEST3
    printf("#if TEST3\n");
#elif TEST5
    printf("#elif TEST5\n");
#else
    printf("#if #else\n");
#endif
}
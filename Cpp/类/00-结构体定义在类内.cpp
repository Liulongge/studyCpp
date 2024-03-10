#include <iostream>

class MyClass
{
private:
    
public:
    typedef struct
    {
        int a = 0;
        int b = 0;
        int c = 0;
    } MyStruct;

    struct MyStruct2;
};

struct MyClass::MyStruct2
{
    int d = 0;
    int e = 0;
};

void print(MyClass::MyStruct *data)
{
    printf("a = %d; b = %d; c = %d\n", data->a, data->b, data->c);
}

void print2(MyClass::MyStruct2 *data)
{
    printf("d = %d; e = %d\n", data->d, data->e);
}

int main()
{
    MyClass::MyStruct test;
    test.a = 1;
    test.b = 2;
    test.c = 3;
    print(&test);

    MyClass::MyStruct2 test2;
    test2.d = 4;
    test2.e = 5;
    print2(&test2);
    return 0;
}
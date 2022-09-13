#include <stdio.h>
#include <arm_neon.h>
#include <iostream>

using namespace std;

int main()
{
    cout << "===========Neon Types===========" << endl;
    cout << "64 bit registers:" << endl;
    cout << "int8x8_t size: " << sizeof(int8x8_t) << endl;
    cout << "int16x4_t size: " << sizeof(int16x4_t) << endl;
    cout << "int32x2_t size: " << sizeof(int32x2_t) << endl;
    cout << "int64x1_t size: " << sizeof(int64x1_t) << endl;
    cout << "float16x4_t size: " << sizeof(float16x4_t) << endl;
    cout << "float32x2_t size: " << sizeof(float32x2_t) << endl;

    cout << "128 bit registers: " << endl;
    cout << "int8x16_t size: " << sizeof(int8x16_t) << endl;
    cout << "int16x8_t size: " << sizeof(int16x8_t) << endl;
    cout << "int32x4_t size: " << sizeof(int32x4_t) << endl;
    cout << "int64x2_t size: " << sizeof(int64x2_t) << endl;
    cout << "float16x8_t size: " << sizeof(float16x8_t) << endl;
    cout << "float32x4_t size: " << sizeof(float32x4_t) << endl;

    return 0;
}
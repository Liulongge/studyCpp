#include <iostream>

using namespace std;

#define TEST(a) cout << "枚举值为: " << a << "枚举字符为: "  << #a << endl

#define DEFINE_TEST 10
typedef enum
{ 
    Mon = 1, 
    Tues, 
    Wed, 
    Thurs, 
    Fri, 
    Sat, 
    Sun 
} enum_test;

int main(int argc, char *argv[])
{
    TEST(Mon);
    TEST(Tues);
    TEST(Wed);
    TEST(Thurs);
    TEST(Fri);
    TEST(Sat);
    TEST(Sun);

    TEST(DEFINE_TEST);
    return 0;
}

// 运行结果:
// 枚举值为: 1枚举字符为: Mon
// 枚举值为: 2枚举字符为: Tues
// 枚举值为: 3枚举字符为: Wed
// 枚举值为: 4枚举字符为: Thurs
// 枚举值为: 5枚举字符为: Fri
// 枚举值为: 6枚举字符为: Sat
// 枚举值为: 7枚举字符为: Sun
// 枚举值为: 10枚举字符为: DEFINE_TEST
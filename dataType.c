#include <stdio.h>
#include <stdint.h>
#include <string.h>
// 枚举类型
enum
{
    ENUM_TEST_0 = 0,
    ENUM_TEST_1,
    ENUM_TEST_2,
    ENUM_TEST_3,
    ENUM_TEST_MAX = 16
} emum_test_e;

// enum emum_test_e
// {
//     ENUM_TEST_0 = 0,
//     ENUM_TEST_1,
//     ENUM_TEST_2,
//     ENUM_TEST_3,
//     ENUM_TEST_MAX = 16
// };

// 结构体
// 定义新的结构体 student_t
typedef struct
{
    char name[100];
    uint8_t age;
    uint8_t class;
} student_t;

// 定义结构题并实例变量
struct
{
    char name[100];
    uint8_t age;
    uint8_t class;
} student2, student3;


int main()
{
    printf("enum: %d\n", ENUM_TEST_MAX);

    student_t student;
    strcpy(student.name, "xiaoming");
    student.age = 10;
    student.class = 1;
    printf("student name: %s\n", student.name);

    strcpy(student2.name, "xiaoguo");
    student2.age = 11;
    student2.class = 2;
    printf("student2 name: %s\n", student2.name);
    return 0;
}
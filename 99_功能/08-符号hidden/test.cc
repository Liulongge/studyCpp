#include "test.h"

// test_01表示是"default"显示定义，说明可以被外界函数调用和导出。
__attribute((visibility("default"))) void test_01()
{
    printf("xxx------->%s()\n", __FUNCTION__);
}

// test_01表示隐士定义，如果gcc编译时，参数为-fvisibility=hidden，则不能被导出和外界调用。
void test_02()
{
    printf("xxx------->%s()\n", __FUNCTION__);
}
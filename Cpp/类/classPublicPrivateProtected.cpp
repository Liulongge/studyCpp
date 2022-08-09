#include <iostream>

using namespace std;
// 访问权限
class Persion
{
public:     // 公共权限  类内/外均可访问
    string m_Name; // 姓名

protected:  // 保护权限  类内可以   类外不可以 访问  儿子可以访问父亲保护的内容
    string m_Car; // 汽车

private:    // 私有权限  类内可以   类外不可以 访问  儿子不可以访问父亲私有内容
    int password; // 银行卡密码

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        password = 123456;
    }
};

int main(int argc, char *argv[])
{
    // 实例化具体对象
    Persion p1;
    p1.m_Name = "李四";
    // p1.m_Car    protected 保护权限内容，类外访问呢不到
    // p1.password private   私有权限内容，类外访问呢不到 

    p1.func();
    return 0;
}

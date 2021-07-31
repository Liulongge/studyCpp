
#include <iostream>
#include <string>
using namespace std;

// 空指针调用成员函数

// C++中空指针也是可以调用成员函数的，但是也是要注意有没有用到this指针
// 如果用到this指针，需要判断保证代码的健壮性

// 总结：
// 空指针可以访问成员函数

class Person
{
public:
    void showClassName()
    {
        cout << "This is person class" << endl;
    }

    void showPersonAge()
    {
        // 报错原因，传入的指针是 null
        // 提高代码健壮性
        if(this == nullptr)
        {
            return ;
        }
        cout << "age = " << this->m_Age << endl;
    }
    int m_Age;

};
void test01()
{
    Person *p = nullptr;
    p->showClassName();
    p->showPersonAge();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}

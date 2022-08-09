#include <iostream>
#include <string>
using namespace std;

// 深拷贝与浅拷贝

// 1.浅拷贝：简单的赋值拷贝操作
// 2.深拷贝：在堆区重新申请空间，进行拷贝操作

// 1.浅拷贝带来的问题是 -> 堆区内存的重复释放 
// 2.浅拷贝的内存要深拷贝解决，避免由编译器提供的浅拷贝带来的该问题 -> 自己实现拷贝构造
// 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

class Persion
{
public:
    Persion()
    {
        cout << "Persion 的默认构造函数" << endl;
    }
    Persion(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
        cout << "Persion 的有参构造函数" << endl;
    }
    // 自己实现拷贝函数，解决浅拷贝到带来的问题
    // 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
    Persion(const Persion &p)
    {
        cout << "Persion 深拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
        // m_Height = p.m_Height; // 编译器默认实现，仅仅拷贝了地址，因此造成了重复释放
        m_Height = new int(*p.m_Height);// 使用深拷贝，解决浅拷贝带来的问题，重新在堆区申请内存
    }

    ~Persion()
    {
        // 析构函数，通常将堆区开辟的数据做释放
        if(m_Height != nullptr)
        {
            delete m_Height;
            // 防止野指针的出现，做一个指向空的操作
            m_Height = nullptr;
        }
        
        cout << "Persion 的析构函数" << endl;
    }
    int m_Age;
    int *m_Height;
};

void test01()
{
    Persion p1(18, 160);
    cout << "p1 的年龄：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;

    Persion p2(p1);
    cout << "p2 的年龄：" << p1.m_Age << endl;
}
int main(int argc, char *argv[])
{
    test01();


    return 0;
}
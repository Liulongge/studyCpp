#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 以二进制的方式对文件进行读写操作
// 打开文件要指定为 ios::binary

// ######## 二进制写文件 #######

// 二进制方式写文件主要利用流对象调用成员函数 write
// 函数原型 ostream& write(const char *buffer, int len);
// 参数解释：字符指针buffer指向内存中的一段存储空间，len是读写字节数

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    // 1.包含头文件
    // #include <fstream>
    // 2.创建刘对象
    // 两部合成一部
    ofstream ofs("person.txt", ios::out | ios::binary);
    // 3.指定打开方式
    // ofs.open("person.txt", ios::out | ios::binary);
    // 4.写数据
    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));
    // 5.关闭文件
    ofs.close();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
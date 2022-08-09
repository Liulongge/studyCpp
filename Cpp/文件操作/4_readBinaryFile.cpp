#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ######## 二进制形式读文件 ########
// 二进制形式读文件主要利用流对象调用成员函数 read
// 函数原型：istream& read(char *buffer, int len);
// 参数解释：字符指针buffer指向内存中一段存储空间，len是读写长度

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    // 1.包好头文件
    //     #include <fstream>
    // 2.创建流对象
    fstream ifs;
    // 3.打开文件并判断文件是否打开成功
    ifs.open("person.txt", ios::in | ios::binary);
    // 判断是否打开成功
    if( !ifs.is_open() )
    {
        cout << "open file failed" << endl;
        return;
    }
    // 4.读数据
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
    // 5.关闭文件
    ifs.close();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
#include <iostream>

using namespace std;

class Student
{
public:    // 公共权限
    // 类中的 属性 和 行为 统一称为  成员
    // 属性   成员属性  成员变量
    // 行为   成员函数  成员方法
    string m_Name;
    int m_Id;
    // 给姓名赋值
    void setName(string name)
    {
        m_Name = name;
    }
    // 给学号赋值
    void setId(int id)
    {
        m_Id = id;
    }
    // 显示信息
    void showStudent()
    {
        cout << "姓名：" << m_Name << "学号：" << m_Id << endl;
    }
};

int main(int argc, char *argv[])
{
    Student s1;
    s1.m_Name = "张三";
    s1.m_Id = 1;
    s1.showStudent();

    Student s2;
    s2.setName("李四");
    s2.setId(2);
    s2.showStudent();

    return 0;
}

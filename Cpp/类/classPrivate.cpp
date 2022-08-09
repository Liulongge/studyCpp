#include <iostream>
#include <string>
using namespace std;

// 成员属性设置为私有
// 优点1： 将所有成员属性设置为私有，可以自己控制读写权限
// 缺点2： 对于读写权限，我们可以检测数据的有效性

class Persion
{
public: // 数据设置为私有之后，通常会暴露对外的 public 接口
    // 设置姓名  可读可写
    void setName(string name)
    {
        m_Name = name;
    }

    // 获取姓名
    string getName()
    {
        return m_Name;
    }

    // 设置年龄
    void setAge(int age)
    {
        if((age < 0) || (age > 150))
        {
            m_Age = 0;
            cout << "输入有误！" << endl;
            return;
        }
        m_Age = age;
    }

    // 获取年龄
    int getAge()
    {
        return m_Age;
    }

    // 设置lover 只写权限
    void setLover(string lover)
    {
        m_Lover = lover;
    }
private:
    // 姓名
    string m_Name;
    // 年龄
    int m_Age;
    // 情人
    string m_Lover;
};

int main(int argc, char *argv[])
{
    Persion P;
    P.setName("张三");
    cout << "姓名： " << P.getName() << endl;
    cout << "年龄： " << P.getAge() << endl;
    P.setLover("小李");
    P.setAge(18);
    cout << "年龄： " << P.getAge() << endl;

    // P.m_Name 不可读写， 私有属性
    return 0;
}
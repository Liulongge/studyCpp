#include<iostream>
#include<queue>
#include<string>

using namespace std;

// queue基本概念
// 概念：queue 是一种先进先出（First In First Out, FIFO）数据结构，他有两个出口

// 队列容器允许从一端新增元素，从另一端移除元素
// 队列中只有 队头 和 队尾 才可以被外界使用，因此队列不允许有遍历的行为
// 队列中进数据称为  ---  入队 push
// 队列中出数据称为  ---  出队 pop

// 生活中案例：排队买票

// 常用接口:
// 1.构造函数
//     queue<T> que;                            queue采用模板类实现，queue对象的默认构造形式
//     queue(const queue &que);                 拷贝构造
// 2.赋值操作
//     queue& operator=(const queue &que);      重载等号操作符
// 3.数据存取
//     push(elem)；                              往队尾添加元素
//     pop();                                    从队头移除一个与元素
//     back();                                   返回最后一个元素
//     front();                                  返回第一个元素
// 4.大小操作
//     empty();                                  判断队列是否为空
//     size();                                   返回队列大小

// 总结：
// 入队             -- push
// 出队             -- pop
// 返回队头元素      -- front
// 返回队尾元素      -- back
// 判断对列是否为空  -- empty
// 返回对列大小      -- size

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    queue<Person> q;

    Person p1("AA", 10);
    Person p2("BB", 20);
    Person p3("CC", 30);
    Person p4("DD", 40);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << "对列大小： " << q.size() << endl;
    // 判断只要队列不为空，查看队头，队尾，出队
    while(!q.empty())
    {
        // 查看对头元素
        cout << "队头元素 - 姓名：" << q.front().m_Name << "， 年龄：" << q.front().m_Age << endl;
        // 查看队尾元素
        cout << "队尾元素 - 姓名：" << q.back().m_Name << "， 年龄：" << q.back().m_Age << endl;
        q.pop();
    }
    cout << "对列大小： " << q.size() << endl;
}

int main()
{
    test01();
    return 0;
}
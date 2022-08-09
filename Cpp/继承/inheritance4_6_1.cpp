#include <iostream>
#include <string>

using namespace std;

// 继承是面向对象三大特征之一
// 有些类与类之间存在特殊的关系
// 我们发现定义这些类时，下级别的成员拥有上一级的共性，还有自己的特性
// 这时候我们就可以考虑利用继承技术，减少重复代码

// 继承的基本语法：
// 例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中间内容不同
// 接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承的意义和好处

// 继承的好处：
// 减少重复的代码

// 语法：
// class 子类 ： 继承方式 父类
// 别称：
// 子类： 派生类
// 父类： 基类

// 派生类中的成员，包含两大部分
// 一类是基类继承过来的，一类是自己添加的成员
// 从基类继承过来的表现其共性，而新增的成员体现了其个性

// 继承实现页面
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void hooter()
    {
        cout << "帮助中心、交流中心、站内地图...（公共底部）" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...（公共分类列表）" << endl;
    }
};

// Java页面，继承BasePage的public部分
class Java : public BasePage
{
public:
    void content()
    {
        cout << "Java 学科视频" << endl;
    }
};

// Python页面
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python 学科视频" << endl;
    }
};

// C++页面
class Cpp : public BasePage
{
public:
    void content()
    {
        cout << "Cpp 学科视频" << endl;
    }
};

void test01()
{
    cout << "Java 下载视频页面如下： " << endl;
    Java java;
    java.header();
    java.hooter();
    java.left();
    java.content();
    cout << "--------------------" << endl;

    cout << "Python 下载视频页面如下： " << endl;
    Python python;
    python.header();
    python.hooter();
    python.left();
    python.content();
    cout << "--------------------" << endl;

    cout << "Cpp 下载视频页面如下： " << endl;
    Cpp  cpp;
    cpp.header();
    cpp.hooter();
    cpp.left();
    cpp.content();
    cout << "--------------------" << endl;
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}
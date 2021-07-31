
#include <iostream>
#include <string>
using namespace std;

// 友元

// 生活中你的家有客厅（public）,你的卧室（Private）
// 客厅所有来的客人都可以进去，但是卧室是私有的，也就是说只有你能进去
// 但是，也可以允许好闺蜜好基友进去
// 在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的的技术
// 友元的目的就是让一个函数或者类 访问另一个类中的私有成员
// 友元的关键词 friend

// 友元的三种实现：
// 1.全局函数做友元
// 2.类做友元
// 3.成员函数做友元

// ###### 成员函数做友元 ######

class Building;

// 好基友的类
class GoodGay
{
public:
    GoodGay();
    // 访问函数 访问buliding中的属性
    void visit();  // 让 visit 函数可以访问 Building 中私有成员函数
    void visit2(); // 让 visit2 函数访问不到 Building 中私有成员函数
private:
    Building *building;
};

// 建筑物的类
class Building
{
    // GoodGay 类是本类的好朋友，可以访问私有成员
    friend void GoodGay::visit();
public:
    Building();
    string m_SittingRoom;
private:
    string m_BedRoom;
};


Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

// 类外写成员函数
GoodGay::GoodGay()
{
    // 创建一个建筑物的对象
    building = new Building;
}

void GoodGay::visit()
{
    cout << "好基友 正在访问：" << building->m_SittingRoom << endl;
    cout << "好基友 正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
    cout << "好基友 正在访问：" << building->m_SittingRoom << endl;
    //cout << "好基友 正在访问：" << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay goodGay;
    goodGay.visit();
    goodGay.visit2();
}


int main(int argc, char *argv[])
{
    test01();

    return 0;
}

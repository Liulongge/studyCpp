
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

// ###### 全局函数做友元 ######

// 建筑物的类
class Building
{
    // goodGay全局函数是 Building的好朋友，可以访问Building中私有成员
    friend void goodGay(Building *building);
public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
    string m_SittingRoom;
private:
    string m_BedRoom;
};

// 全局函数
void goodGay(Building *building)
{
    cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;

    // 私有成员函数 类外不能访问
    // 此处在类中已经声明 goodGay 为其 友类
    cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;

}

void test01()
{
    Building building;
    goodGay(&building);
}


int main(int argc, char *argv[])
{
    test01();

    return 0;
}

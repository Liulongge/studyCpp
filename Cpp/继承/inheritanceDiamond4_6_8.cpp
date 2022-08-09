#include <iostream>
#include <string>

using namespace std;

// 菱形继承

// 概念
// 两个派生类继承同一基类
// 又有某个类同时继承这两个派生类
// 这种继承被称为菱形继承，或者派生继承

//      动物
//  羊        驼 
//   草泥马(羊驼)

// 1.羊继承了动物的数据，骆驼同样继承了动物的数据，当草泥马使用数据的时候，就会产生二义性
// 2.草泥马继承自动物的数据，继承了两份，其实我们应该能清楚，这份数据我们只需要一份就可以

// vbptr: 虚基类指针
// v: virtual, b: base, ptr: pointer
// 虚继承解决了数据有两份的问题
// !!!继承的不是两份数据，而是两份指针，指向基类!!!

class Animal
{
public:
    int m_Age;
};

// 利用虚继承 解决菱形继承的问题
// 在继承之前加上关键字 virtual 变成虚继承
// 虚继承可以解决菱形继承的问题
class Sheep : virtual public Animal
{

};

class Tuo : virtual public Animal
{

};

class SheepTuo : public Sheep, public Tuo
{

};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    // 当出现菱形继承的时候，有两个父类拥有相同的数据，需要加作用域区分
    // 羊驼有两个年龄
    // 菱形继承导致数据有两份，资源浪费
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    
    // 28
    // 虚继承解决菱形继承的问题，数据只有一份
    cout << "st.m_Age = " << st.m_Age << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
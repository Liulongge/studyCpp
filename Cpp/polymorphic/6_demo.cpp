#include <iostream>
#include <string>
using namespace std;

// 多态，多种形态
// 多态是C++面向对象三大特征之一
// 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
// 动态重载：派生类 和 虚函数实现运行时多态

// 案例描述
// 电脑主要组成部分为CPU（用于计算）、显卡（用于显示）、内存条（用于存储）
// 将每个零部件封装出抽象基类，并且提供不同厂商生产的不同的零件，例如intel和lenovo
// 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
// 测试时组装三台不同的电脑进行工作

// 抽象的CPU类
class CPU
{
public:
    // 抽象的计算函数，纯虚函数
    virtual void caculate() = 0;
};

// 抽象显卡
class VideoCard
{
public:
    // 抽象的显示函数，纯虚函数
    virtual void display() = 0;
};

// 抽象内存条
class Memory
{
public:
    // 抽象的存储函数，纯虚函数
    virtual void storage() = 0;
};

class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    void work()
    {
        m_cpu->caculate();
        m_vc->display();
        m_mem->storage();
    }
    ~Computer()
    {
        if(m_cpu != nullptr)
        {
            delete m_cpu;
            m_cpu = nullptr;
        }
        if(m_vc != nullptr)
        {
            delete m_vc;
            m_vc = nullptr;
        }
        if(m_mem != nullptr)
        {
            delete m_mem;
            m_mem = nullptr;
        }
    }
private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

// 具体厂商
// lenovo
class LenovoCpu : public CPU
{
public:
    virtual void caculate()
    {
        cout << "Lenovo 的cpu开始计算了" << endl;
    }
};

class LenovoVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Lenovo 的显卡开始显示了" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Lenovo 的内存条开始存储了" << endl;
    }
};

// intel
class IntelCpu : public CPU
{
public:
    virtual void caculate()
    {
        cout << "Intel 的cpu开始计算了" << endl;
    }
};

class IntelVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Intel 的显卡开始显示了" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Intel 的内存条开始存储了" << endl;
    }
};

void test01()
{
    // 第一台电脑的零件
    CPU *intelCpu = new IntelCpu;
    VideoCard *intelCard = new IntelVideoCard;
    Memory *intelMem = new IntelMemory;

    // 创建第一台电脑
    Computer *computer = new Computer(intelCpu, intelCard, intelMem);
    computer->work();
    delete computer;

    // 第二台电脑的零件
    CPU *lenovoCpu = new LenovoCpu;
    VideoCard *lenovoCard = new LenovoVideoCard;
    Memory *lenovoMem = new LenovoMemory;

    // 创建第二台电脑
    computer = new Computer(lenovoCpu, lenovoCard, lenovoMem);
    computer->work();
    delete computer;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
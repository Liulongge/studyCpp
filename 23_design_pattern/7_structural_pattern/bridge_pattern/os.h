//OS.h
#ifndef OS_H_
#define OS_H_

#include <iostream>
using namespace std;

//抽象的操作系统类
class OS
{
public:
    virtual std::string GetOS() = 0;
    virtual ~OS(){};
};

//IOS类的实现
class IOS : public OS
{
public:
    virtual std::string GetOS()
    {
        return "IOS Operator System";
    }
};

//塞班类的实现
class SaiBian : public OS
{
public:
    virtual std::string GetOS()
    {
        return "SaiBian Operator System";
    }
};

//IOS某个版本的实现
class IOSSubSystem1 : public IOS
{
public:
    virtual std::string GetOS()
    {
        return "IOS 5.1.1 Operator System";
    }
};

//IOS某个版本的实现
class IOSSubSystem2 : public IOS
{
public:
    virtual std::string GetOS()
    {
        return "IOS 10.1.1 Operator System";
    }
};

//塞班系统某个类的实现
class SaiBianSubSystem1 : public SaiBian
{
public:
    virtual std::string GetOS()
    {
        return "SaiBian 1.1.0 Operator System";
    }
};

//塞班系统某个类的实现
class SaiBianSubSystem2 : public SaiBian
{
public:
    virtual std::string GetOS()
    {
        return "SaiBian 1.1.1 Operator System";
    }
};

#endif
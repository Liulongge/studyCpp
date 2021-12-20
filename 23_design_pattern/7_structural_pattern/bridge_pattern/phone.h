//phone.h
#ifndef PHONE_H_
#define PHONE_H_

#include "os.h"

#ifndef DELETE_OBJECT
#define DELETE_OBJECT(p) {if(NULL != (p)){delete (p); (p) = NULL;}}
#endif

//抽象的手机类
class Phone
{
public:
    virtual void SetOS() = 0;
    virtual ~Phone(){};
};

//苹果手机类，依赖抽象的操作系统
class iPhone : public Phone
{
public:
    iPhone(OS* os)
    {
        m_pOS = os;
    }
    ~iPhone()
    {
        DELETE_OBJECT(m_pOS);
    }
    virtual void SetOS()
    {
        cout << "Set The OS: " << m_pOS->GetOS().c_str() << endl;
    }
private:
    OS* m_pOS;
};

//诺基亚手机类，以来抽象的操作系统
class Nokia : public Phone
{
public:
    Nokia(OS* os)
    {
        m_pOS = os;
    }
    ~Nokia()
    {
        DELETE_OBJECT(m_pOS);
    }

    virtual void SetOS()
    {
        cout << "Set The OS: " << m_pOS->GetOS().c_str() << endl;
    }
private:
    OS* m_pOS;
};
#endif
#include <iostream>
#include "os.h"
#include "phone.h"

using namespace std;

#ifndef DELETE_OBJECT
#define DELETE_OBJECT(p) {if(NULL != (p)){delete (p); (p) = NULL;}}
#endif

int main()
{
    OS* pIOS1 = new IOSSubSystem1(); //创建一个操作系统
    Phone* iPhone4 = new iPhone(pIOS1);//应用到该手机上
    iPhone4->SetOS();

    OS* pIOS2 = new IOSSubSystem2();//创建一个操作系统
    Phone* iPhone6 = new iPhone(pIOS2);//应用到该手机上
    iPhone6->SetOS();

    OS* pSaiBian1 = new SaiBianSubSystem1();//创建一个操作系统
    Phone* Nokia1 = new Nokia(pSaiBian1);//应用到该手机上
    Nokia1->SetOS();

    OS* pSaiBian2 = new SaiBianSubSystem2();//创建一个操作系统
    Phone* Nokia2 = new Nokia(pSaiBian2);//应用到该手机上
    Nokia2->SetOS();

    DELETE_OBJECT(iPhone4);
    DELETE_OBJECT(iPhone6);
    DELETE_OBJECT(Nokia1);
    DELETE_OBJECT(Nokia2);
    return 0;
}
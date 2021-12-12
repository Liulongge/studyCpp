#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;

class Prototype
{
public:
	Prototype(string str) // 构造函数
    {
	    m_attr = str;
    }
	void ShowAttr() // 显示属性
    {
	    cout << m_attr << endl;
    }
	void SetAttr(string str) // 设置属性
    {
	    m_attr = str;
    }
    virtual ~Prototype(){}
	virtual Prototype *Clone()=0; // 纯虚函数，克隆
private:
	string m_attr; //属性
};

class ConcreatePrototype:public Prototype
{
public:
	ConcreatePrototype(string attr):Prototype(attr){}
    ~ConcreatePrototype(){}
	virtual Prototype *Clone() // 基类中纯虚函数的实现
    {
        ConcreatePrototype *p = new ConcreatePrototype(""); // 创建新的对象，属性为"空"
	    *p = *this; // 当前对象的拷贝
	    return p;
    }
};

int main(int argc, char **arv)
{
	/* 创建一个原型对象0 */
	// ConcreatePrototype *pConcretePrototye0 = new ConcreatePrototype("Init");
    Prototype *pConcretePrototye0 = new ConcreatePrototype("Init");
	cout << "pConcretePrototye0属性:";
	pConcretePrototye0->ShowAttr();
	
	/* 修改原型属性 */
	pConcretePrototye0->SetAttr("Second");	
	cout << "pConcretePrototye0属性:";
	pConcretePrototye0->ShowAttr();

	/* 通过原型对象0拷贝(克隆)一个对象1 */
	// ConcreatePrototype *pConcretePrototye1 = (ConcreatePrototype*)pConcretePrototye0->Clone();
    Prototype *pConcretePrototye1 = (ConcreatePrototype*)pConcretePrototye0->Clone();
	cout << "pConcretePrototye1属性:";
	pConcretePrototye1->ShowAttr();	/* 对象1和对象0的属性是一样的 */

	delete pConcretePrototye0;
	delete pConcretePrototye1;
}

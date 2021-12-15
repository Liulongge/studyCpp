#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;

//基类 -> 抽象苹果
class AbstractApple {
public:
	virtual void ShowName() = 0;
};

//派生类 -> 中国苹果
class ChinaApple :public AbstractApple {
public:
	virtual void ShowName() {
		cout << "中国苹果！" << endl;
	}
};

//派生类 -> 美国苹果
class USAApple :public AbstractApple {
public:
	virtual void ShowName() {
		cout << "美国苹果！" << endl;
	}
};

//派生类 -> 日本苹果
class JapanApple :public AbstractApple {
public:
	virtual void ShowName() {
		cout << "日本苹果！" << endl;
	}
};

//基类 -> 抽象香蕉
class AbstractBanana {
public:
	virtual void ShowName() = 0;
};

//派生类 -> 中国香蕉
class ChinaBanana :public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "中国香蕉！" << endl;
	}
};

//派生类 -> 美国香蕉
class USABanan :public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "美国香蕉！" << endl;
	}
};

//派生类 -> 日本香蕉
class JapanBanan :public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "日本香蕉！" << endl;
	}
};

//基类 -> 抽象鸭梨
class AbstractPear {
public:
	virtual void ShowName() = 0;
};


//派生类 -> 中国鸭梨
class ChinaPear:public AbstractPear{
public:
	virtual void ShowName() {
		cout << "中国鸭梨！" << endl;
	}
};

//派生类 -> 美国鸭梨
class USAPear :public AbstractPear {
public:
	virtual void ShowName() {
		cout << "美国鸭梨！" << endl;
	}
};

//派生类 -> 日本鸭梨
class JapanPear :public AbstractPear {
public:
	virtual void ShowName() {
		cout << "日本鸭梨！" << endl;
	}
};


//基类 -> 抽象工厂 针对产品族
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};

//派生类 -> 中国工厂
class ChinaFactory :public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana(){
		return new ChinaBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new ChinaPear;
	}
};

//派生类 -> 美国工厂
class USAFactory :public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new USAApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new USABanan;
	}
	virtual AbstractPear* CreatePear() {
		return new  USAPear;
	}
};

//派生类 -> 日本工厂
class JapanFactory :public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new JapanBanan;
	}
	virtual AbstractPear* CreatePear() {
		return new  JapanPear;
	}
};

void test01() {
	AbstractFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear* pear = NULL;

	//中国工厂
	factory = new ChinaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();

	apple->ShowName();
	banana->ShowName();
	pear->ShowName();
}

int main() {
	test01();
	return 0;
}

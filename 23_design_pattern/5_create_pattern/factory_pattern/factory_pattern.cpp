#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;

//基类 -> 抽象水果
class AbstractFruit {
public:
	virtual void ShowName() = 0;
	virtual ~AbstractFruit(){};
};

//派生类 -> 苹果
class Apple :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是苹果!" << endl;
	}
	virtual ~Apple(){};
};

//派生类 -> 香蕉
class Banana :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是香蕉!" << endl;
	}
	virtual ~Banana(){};
};

//派生类 -> 鸭梨
class Pear :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是鸭梨!" << endl;
	}
	virtual ~Pear(){};
};

//基类 -> 抽象工厂
class AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
	virtual ~AbstractFruitFactory(){};
};


//派生类 -> 苹果工厂
class AppleFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() {
		return new Apple;
	}
	virtual ~AppleFactory(){};
};

//派生类 -> 香蕉工厂
class BananaFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() {
		return new Banana;
	}
	virtual ~BananaFactory(){};
};

//派生类 -> 鸭梨工厂
class PearFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit* CreateFruit() {
		return new Pear;
	}
	virtual ~PearFactory(){};
};


void test01() {
	AbstractFruitFactory* factory = NULL;
	AbstractFruit* fruit = NULL;

	//创建一个苹果工厂
	factory = new AppleFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	//创建一个香蕉工厂
	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	//创建一个鸭梨工厂
	factory = new PearFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;
	fruit = NULL;
	factory = NULL;

}

int main() {
	test01();
	return 0;
}

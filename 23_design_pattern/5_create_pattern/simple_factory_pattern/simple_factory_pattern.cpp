#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;

//基类 -> 抽象水果
class AbstractFruit {
public:
	virtual void ShowName() = 0;  // 纯虚函数
	virtual ~AbstractFruit() {}   // 虚析构函数
};

// 派生类 -> 苹果
class Apple :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是苹果!" << endl;
	}
};

// 派生类 -> 香蕉
class Banana :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是香蕉!" << endl;
	}
};

// 派生类 -> 鸭梨
class Pear :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是鸭梨!" << endl;
	}
};

// 水果工厂
class FruitFactor {
public:
	static AbstractFruit * CreateFruit(string flag) {
		if (flag == "apple") {
			return new Apple;
		}
		else if (flag == "banana") {
			return new Banana;
		}
		else if (flag == "pear") {
			return new Pear;
		}
		else {
			return NULL;
		}
	}
	virtual ~FruitFactor(){}
};

void test01() {
	FruitFactor* factory = new FruitFactor;
	AbstractFruit* fruit = factory->CreateFruit("apple");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("banana");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("pear");
	fruit->ShowName();
	delete fruit;

	fruit = NULL;
	delete factory;
	factory = NULL;
}

int main(){
	test01();
	return 0;
}

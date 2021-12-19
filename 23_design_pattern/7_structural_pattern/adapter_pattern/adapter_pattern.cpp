#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 不适用适配器，存在问题
// void myPrintf(int v1,int v2) {
// 		cout << v1 + v2 << endl;
// 	}

void myPrintf(int v1) {
		cout << v1 << endl;
	}

//适配器模式 就是将已经写好的接口，但是这个接口不符合需求
//将写好的接口转换成目标接口

//这函数我已经写好
struct Myprint{
	void operator()(int v1,int v2) {
		cout << v1 + v2 << endl;
	}
};

//基类 -> 定义目标接口 我要是配偶 适配成什么样的，
//要适配成只能传一个参数的，适配for_each第三个参数的适用
class Target {
public:
	virtual void operator()(int v) = 0;
};

//写适配器
class Adapater :public Target {
public:
	Adapater(int param) {
		this->param = param;
	}
	virtual void operator() (int v) {
		print(v,param);
	}
public:
	Myprint print;
	int param;
};

//MyBind2nd，原来param固定的10，现在提供一个方法改
Adapater MyBind2nd(int v) {
	return Adapater(v);
}


int main(void) {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	
	//适配器模式的运用
	//for_each()的第三个参数是个带一个参数的函数，但是Myprint需要两个参数

	// too few arguments to function call, expected 2, have 1
	// for_each(v.begin(),v.end(), myPrintf);
	for_each(v.begin(),v.end(), MyBind2nd(100));

	return 0;
}

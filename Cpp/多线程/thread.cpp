// g++ thread.cpp -o demo -std=c++11

#include<iostream>
#include<string>
#include<thread>

using namespace std;

// c++中线程的创建一般是通过std::thread类实现的，具体的实现方式有以下几种：

// 1, 使用函数名创建
void pcreat(int a, int b) 
{
	cout << "start, parmeter a = " << a << ", b =" << b << endl;
}

// 2, 使用类对象创建
class X
{
public:
	X() { cout << "constructor!" << endl; }
	X(const X & m) { cout << "copy constructor called !" << endl; }
	void operator()(int a)   // 重载括号运算符。如果无参则为void operator()(){...}
	{
		cout << "start! " << a << endl;
	}
};

// 3, 使用lambda创建

// 4, 使用成员函数创建
// 这里有两种方法通过成员函数创建。而这两种方法恰好也就是静态成员函数和非静态成员函数的区别。
// 静态成员函数与对象无关，只属于类本身，因此在创建线程时只需要给出静态成员函数地址即可; 
// 而非静态成员函数是属于对象的，只有在对象创建后才能够调用，因此在创建线程时必须还要传递对象的地址。

// 4.1 通过静态成员函数创建线程：
class A
{
public:
    static void fun(int a)
    {
		cout << a << endl;
		return;
	}
};

// 4.2 非静态成员函数创建线程：
class B
{
public:
    void fun(int a)
	{
		cout << a << endl;
		return;
	}
 
};

int main()
{
    // 1, 使用函数名创建
	thread p1(pcreat, 4, 5);  //如果函数无参则省略第二个参数，多参数直接加在后面即可

    // 2, 使用类对象创建
    X a;
	thread p2(a, 4);  //以对象a创建线程，并传递参数4，无参的话直接省略第二个参数，更多的参数直接加在后面

    // 3, 使用lambda创建
    auto ff = [](int a, int b){ 
              cout << "lambda pthread creat"; 
              cout << "a = " << a << ", b = " << b << endl; };
 
	thread p3(ff, 3, 4);

    // 4.1 通过静态成员函数创建线程
    int x = 5;
	thread p4(&A::fun, x);

    // 4.2 非静态成员函数创建线程
    B b;
	thread p5(&B::fun, &b, x); //必须传入对象的地址，即this指针，才能找到线程函数的地址

    p1.join();
    p2.join();
    p3.join();
    p4.join();
    p5.join();
    return 0;
}
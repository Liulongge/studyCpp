#include<iostream>
#include<string>
#include<thread>
#include<mutex>
using namespace std;
mutex m_lock;

// 1、使用互斥锁(mutex):
// 注意: 必须手动调用unlock(), 否则资源不释放
// 在C++中, 通过构造std::mutex的实例创建互斥元, 调用成员函数lock()来锁定它, 调用unlock()来解锁,
// 这能满足我们的需求。不过一般不推荐这种做法, lock()和unlock()是成对出现的, 需要手动解锁, 
// 若在手动释放锁前程序异常, 没有调用unlock(),这个资源会一直被锁着，没发释放，会导致其他异常.

// void f() {
// 	m_lock.lock();
// 	cout << "线程id:" << this_thread::get_id() << endl;
// 	m_lock.unlock();
// }

// 2. 使用std::lock_guard
// 注意: 析构时自动释放, 不能手动调用unlock(),否则析构时再次调用,会报异常.
// 在作用域内创建lock_guard对象时,会尝试获得锁(mutex::lock()),没有获得就像其他锁一样阻塞在原地.
// 在lock_guard的析构函数内会释放锁(mutex::unlock()),不需要我们手动释放.
// 实际编程中建议使用lock_guard, 防止在获得锁后程序运行出现异常退出而导致锁死.
// 注意: 使用lock_guard时不要手动unlock()，否则lock_guard的析构函数中解锁时就会报异常.

void f() {
	lock_guard<mutex> lg(m_lock);
	cout << "线程id:" << this_thread::get_id() << endl;
}

// 3. 使用unique_lock
// 注意：若没有手动调用unlock()，析构时自动释放；若手动调用unlock()，调用时释放。
// unique_lock也是类模板，和lock_guard差不多，也是构造函数中加锁，析构函数解锁，符合RAII原则。
// 但unique_lock解锁能力更灵活，给我们提供了更好的优化代码能力。
// lock_guard在创建获得锁之后必须要等到析构时才会释放锁，
// 这样就造成其他线程在执行不涉及临界资源的代码时浪费了时间，大大降低效率。
// 而unique_lock在创建获得锁之后可等到析构时才会释放锁，也可以手动释放锁，
// 这样可以在执行不涉及临界资源的代码是解锁，提高效率。

void ff() {
	unique_lock<mutex> lg(m_lock);
	cout << "ff() 加锁." << endl;
	lg.unlock(); 
	cout << "ff() 已经解锁了." << endl;
}

int main()
{
    thread tTest1(f);
	thread tTest2(f);
	thread tTest3(ff);
	thread tTest4(ff);
	tTest1.join();
	tTest2.join();
	tTest3.join();
	tTest4.join();
	return 0;
}

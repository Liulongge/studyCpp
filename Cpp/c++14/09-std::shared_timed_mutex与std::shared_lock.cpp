// C++14通过std::shared_timed_mutex和std::shared_lock来实现读写锁，
// 保证多个线程可以同时读，但是写线程必须独立运行，写操作不可以同时和读操作一起进行。


// 在 C++14 中，std::shared_timed_mutex 和 std::shared_lock 提供了对共享资源的读-写锁机制的支持。这种机制允许多个线程同时读取资源（即共享锁），但当有线程需要写入时，则独占资源（即独占锁），以确保数据一致性。

// std::shared_timed_mutex
// std::shared_timed_mutex 是一个互斥量类，它支持两种类型的锁定：独占锁定（exclusive locking）和共享锁定（shared locking）。它还提供了带有超时功能的方法，以便线程可以在尝试获取锁时等待特定的时间段。

// 主要成员函数
// void lock_shared();：获得共享锁。
// bool try_lock_shared();：尝试获得共享锁，如果不能立即获得则返回 false。
// template <class Rep, class Period> bool try_lock_shared_for(const std::chrono::duration<Rep, Period>& rel_time);：尝试在指定时间内获得共享锁。
// template <class Clock, class Duration> bool try_lock_shared_until(const std::chrono::time_point<Clock, Duration>& abs_time);：尝试直到指定时间点获得共享锁。
// void unlock_shared();：释放共享锁。
// void lock();：获得独占锁。
// bool try_lock();：尝试获得独占锁，如果不能立即获得则返回 false。
// template <class Rep, class Period> bool try_lock_for(const std::chrono::duration<Rep, Period>& rel_time);：尝试在指定时间内获得独占锁。
// template <class Clock, class Duration> bool try_lock_until(const std::chrono::time_point<Clock, Duration>& abs_time);：尝试直到指定时间点获得独占锁。
// void unlock();：释放独占锁。
// std::shared_lock
// std::shared_lock 是一个模板类，它提供了一个更高层次的接口来管理 std::shared_timed_mutex 的共享锁。它简化了共享锁的获取和释放，并且可以与作用域结合使用，从而自动管理锁的生命周期。

// 主要成员函数
// explicit shared_lock(std::shared_timed_mutex& m);：构造函数，尝试获得关联互斥量上的共享锁。
// ~shared_lock();：析构函数，自动释放共享锁。
// void lock();：获得共享锁。
// bool try_lock();：尝试获得共享锁，如果不能立即获得则返回 false。
// template <class Rep, class Period> bool try_lock_for(const std::chrono::duration<Rep, Period>& rel_time);：尝试在指定时间内获得共享锁。
// template <class Clock, class Duration> bool try_lock_until(const std::chrono::time_point<Clock, Duration>& abs_time);：尝试直到指定时间点获得共享锁。
// void unlock();：释放共享锁。
// void swap(shared_lock& other);：交换两个 shared_lock 对象的状态。

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <shared_mutex>

// 定义一个全局变量作为共享资源
int shared_resource = 0;
std::shared_timed_mutex mtx;

// 读者线程函数
void reader(int id) {
    std::shared_lock<std::shared_timed_mutex> lock(mtx);
    std::cout << "Reader " << id << " sees value: " << shared_resource << '\n';
}

// 写者线程函数
void writer(int id, int new_value) {
    std::unique_lock<std::shared_timed_mutex> lock(mtx);
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // 模拟写操作延迟
    shared_resource = new_value;
    std::cout << "Writer " << id << " wrote value: " << new_value << '\n';
}

int main() {
    const int num_readers = 5;
    const int num_writers = 2;

    // 创建读者线程
    std::vector<std::thread> readers;
    for (int i = 0; i < num_readers; ++i) {
        readers.emplace_back(reader, i + 1);
    }

    // 创建写者线程
    std::vector<std::thread> writers;
    for (int i = 0; i < num_writers; ++i) {
        writers.emplace_back(writer, i + 1, i * 10);
    }

    // 等待所有线程完成
    for (auto& t : readers) {
        if (t.joinable()) t.join();
    }
    for (auto& t : writers) {
        if (t.joinable()) t.join();
    }

    return 0;
}
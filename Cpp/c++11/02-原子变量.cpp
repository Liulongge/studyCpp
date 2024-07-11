// g++ 02-原子变量.cpp -o demo -std=c++11 -lpthread

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> g_counter(0); // 定义一个原子变量counter并初始化为0
// int g_counter(0); // 定义一个原子变量counter并初始化为0

void increment_counter(int n)
{
    for (int i = 0; i < n; ++i)
    {
        g_counter += 2; // 原子地增加counter的值
    }
}

int main()
{
    for(int i = 0; i < 100; i++)
    {
        const int num_threads = 10;
        std::vector<std::thread> threads;
        g_counter = 0;
        // 创建10个线程，每个线程将counter增加1000次
        for (int i = 0; i < num_threads; ++i)
        {
            threads.emplace_back(increment_counter, 1000);
        }
        // 等待所有线程完成
        for (auto &t : threads)
        {
            t.join();
        }
        std::cout << "Final g_counter value is " << g_counter << std::endl; // 输出最终的counter值
    }

    return 0;
}
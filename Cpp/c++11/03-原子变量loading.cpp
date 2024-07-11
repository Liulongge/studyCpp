#include <iostream>  
#include <atomic>  
#include <thread>  
#include <vector>  
#include <chrono>  
#include <mutex>
#include <chrono>  

// std::atomic<int> g_counter1(0);  
// std::atomic<int> g_counter2(0); 
// std::atomic<int> g_counter3(0); 
// std::atomic<int> g_counter4(0); 
// 互斥锁  
std::mutex g_mtx; 
int g_counter1 = 0;
int g_counter2 = 0;
int g_counter3 = 0;
int g_counter4 = 0;

void increment_counter(int n, int delay_ms)
{  
    while(1)
    {
        // 使用高精度时钟获取当前时间点  
        auto now = std::chrono::high_resolution_clock::now();  
        auto duration = now.time_since_epoch();  
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();   

        std::unique_lock<std::mutex> lock(g_mtx);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms)); // 模拟定时器延迟  
        g_counter1++;
        g_counter2++;
        g_counter3++;
        g_counter4++;
        auto microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();   
        // std::cout << microseconds2 - microseconds << std::endl;
          
    }
}  
  
int main() {  
    const int num_threads = 1000;  
    const int increment_count = 100;  
    const int delay_ms = 10; // 每次增加之间的延迟（毫秒）  
  
    std::vector<std::thread> threads;  
  
    // 创建多个线程，每个线程将counter增加increment_count次，每次增加之间有延迟  
    for (int i = 0; i < num_threads; ++i) {  
        threads.emplace_back(increment_counter, increment_count, delay_ms);  
    }  
  
    // 等待所有线程完成  
    for (auto& t : threads) {  
        t.join();  
    }  
  
    return 0;  
}
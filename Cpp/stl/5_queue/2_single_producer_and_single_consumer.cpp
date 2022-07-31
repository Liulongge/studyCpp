// g++ 2_single_producer_and_single_consumer.cpp -std=c++11 -o demo
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <queue>

using namespace std;
template <typename T>
class SafeQueue{
public:
    SafeQueue()
    {
    }
    ~SafeQueue()
    {
    }

    void push(T data)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(data);
        cv_.notify_all();
    }

    int get(T& data)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if(queue_.empty()) 
        {
            cv_.wait(lock);
        }
        data = queue_.front();
        queue_.pop();
        return 0;
    }

    int get(T& data, int time_ms)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if(queue_.empty()) 
        {
            auto start = chrono::high_resolution_clock::now(); //当前时间
            auto end = start + chrono::milliseconds(time_ms); //结束时间
            if(cv_.wait_until(lock, end) == cv_status::timeout)
            {
                cout << "time out" << endl;
                return -1;
            }
        }
        data = queue_.front();
        queue_.pop();
        return 0;
    }

private:
    queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
};

SafeQueue<int> sq;


void consumer()
{
	while (1)
    {
        int i;
        sq.get(i, 5);
        cout << "取出来的数据是：" << i << endl;
    }
}

void producer()
{
    while (1)
    {
        static int i;
        i++;
        cout << "生产的数据是：" << i << endl;
        sq.push(i);
        sleep(1);
        
    }	
}

int main()
{
	thread p1(producer);
	thread s1(consumer);
	p1.join();
	s1.join();
	return 0;
}
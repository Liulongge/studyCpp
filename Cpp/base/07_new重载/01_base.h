#include <iostream>
#include <vector>
#include <map>
class MyRuntime {  
public:  
    // // 自定义的new操作符  
    // void* operator new(size_t size)
    // {
    //     std::cout << "class new: " << size << "\n";  
    //     return ::operator new(size); // 调用全局的new操作符  
    // }  
  
    // // 自定义的delete操作符  
    // void operator delete(void* ptr) noexcept
    // {  
    //     std::cout << "class delete\n";  
    //     ::operator delete(ptr); // 调用全局的delete操作符  
    // }  

    // 构造函数和析构函数  
    MyRuntime() 
    {
        // num = new int(0);
        // test_vector.push_back(1);
        // test_vector.push_back(4);
        // test_vector.push_back(4);
        test_map[1] = 0;
        test_map[2] = 0;
        test_map[3] = 0;
    }
    ~MyRuntime()
    {
        // delete num;
        // test_vector.clear();
    }  

    // std::vector<int> test_vector;
    std::map<int, int> test_map;
    int *num = nullptr;
};
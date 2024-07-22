#include <new> // 包含全局的new和delete的声明  
#include <iostream>  
#include "01_base.h"

class MyClass:public MyRuntime
{};
void* operator new(std::size_t size)
{
    std::cout << "global new: " << size << "   " << __FUNCTION__ << "\n";  
    return std::malloc(size); // 注意：这里使用了malloc而不是全局的new  
}  

void operator delete(void* ptr) noexcept
{  
    std::cout << "global delete\n";  
    std::free(ptr); // 对应的，使用free来释放  
}

// 注意：上面的实现是简单的示例，可能不适用于所有情况，特别是异常安全和多线程环境。  

int main()
{
    MyClass* obj = new MyClass(); // 使用全局的new  
    // int *num = new int(10);
    delete obj; // 使用全局的delete 
    // delete  num;
    return 0;  
}
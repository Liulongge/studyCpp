// main 50
// func1 begin
//       [ + ] 申请内存: 4
// func1 endl
//       [ - ] 释放内存
// main 52
// func2 begin
//       [ + ] 申请内存: 4
// func2 endl
// main 54
//       [ + ] 申请内存: 4
// main 56
// Value: 42
// main 58
//       [ - ] 释放内存
//       [ - ] 释放内存

#include <memory>  
#include <iostream>  

void* operator new(std::size_t size)
{
    std::cout << "      [ + ] 申请内存: " << size << "\n";  
    return std::malloc(size); // 注意：这里使用了malloc而不是全局的new  
}  

void operator delete(void* ptr) noexcept
{  
    std::cout << "      [ - ] 释放内存\n";  
    std::free(ptr); // 对应的，使用free来释放  
}

void func1(void)
{
    std::cout << __FUNCTION__ << " begin\n";
    std::unique_ptr<int> ptr(new int(42)); 
    std::cout << __FUNCTION__ << " endl" << std::endl;
}

std::unique_ptr<int> func2(void)
{
    std::cout << __FUNCTION__ << " begin\n";
    std::unique_ptr<int> ptr(new int(42)); 
    std::cout << __FUNCTION__ << " endl" << std::endl;
    return ptr;
}

int main() 
{
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    func1();
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    std::unique_ptr<int> ptr0 = func2();
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    std::unique_ptr<int> ptr(new int(42));
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    std::cout << "Value: " << *ptr << std::endl;
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    // 当 ptr 离开作用域时，所指向的 int 会被自动删除  
    
    return 0;  
}
#include <iostream>  
#include <cstring> // 用于 std::memcpy  
  
// namespace MyMemory {  
    // 简单的内存分配器  
    void* operator new(std::size_t size) {  
        std::cout << "Allocating " << size << " bytes in MyMemory namespace\n";  
        return std::malloc(size);  
    }  
  
    void operator delete(void* ptr) noexcept {  
        std::cout << "Deallocating pointer in MyMemory namespace\n";  
        std::free(ptr);  
    }  
  
    // 示例类，使用命名空间中的 new 和 delete  
    class MyClass {  
    public:  
        MyClass(int size) {  
            data = new char[size]; // 使用 MyMemory 命名空间中的 new  
            std::memset(data, 0, size);  
        }  
  
        ~MyClass() {  
            delete[] data; // 使用 MyMemory 命名空间中的 delete  
        }  
  
    private:  
        char* data;  
    };  
// }  
  
int main() {  
    // 在 MyMemory 命名空间中创建 MyClass 对象  
    // MyClass obj(100);  
  
    // 注意：以下代码不会使用 MyMemory 命名空间中的 new/delete  
    // 因为这是全局作用域中的 new/delete  
    // int* globalArray = new int[5];  
    // delete[] globalArray;  
    std::vector<int> num;
    num.push_back(1);
    num.push_back(1);
    return 0;  
}
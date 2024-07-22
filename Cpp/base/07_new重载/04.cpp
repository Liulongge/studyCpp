// my_file.cpp

#include <iostream>

namespace MyFileNamespace {

    void* operator new(size_t size) {
        void* ptr = ::operator new(size);
        std::cout << "Memory allocated in my_file.cpp: " << size << " bytes\n";
        return ptr;
    }

    void operator delete(void* ptr) noexcept {
        std::cout << "Memory deallocated in my_file.cpp\n";
        ::operator delete(ptr);
    }

} // namespace MyFileNamespace

using namespace MyFileNamespace;
using MyFileNamespace::operator new;
using MyFileNamespace::operator delete;
// 使用命名空间内的new和delete
int main() {
    int* p = new int(10);
    delete p;
    return 0;
}
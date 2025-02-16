#include <iostream>
#include <cstdlib> // 包含 malloc 和 free

class RAIIMemory {
public:
    // 构造函数，申请内存
    RAIIMemory(size_t size) : size_(size), data_(nullptr) {
        data_ = static_cast<int*>(std::malloc(size * sizeof(int))); // 使用 malloc
        if (!data_) {
            std::cerr << "Memory allocation failed for size " << size_ << std::endl;
        } else {
            std::cout << "Memory allocated of size " << size_ << std::endl;
        }
    }

    // 析构函数，释放内存
    ~RAIIMemory() {
        if (data_) {
            std::free(data_); // 使用 free 释放内存
            std::cout << "Memory deallocated of size " << size_ << std::endl;
        }
    }

    // 移动构造函数
    RAIIMemory(RAIIMemory&& other) noexcept
        : size_(other.size_), data_(other.data_) {
        // 将原对象的数据指针置为空，避免重复释放
        other.size_ = 0;
        other.data_ = nullptr;
        std::cout << "Move constructor called" << std::endl;
    }

    // 移动赋值运算符
    RAIIMemory& operator=(RAIIMemory&& other) noexcept {
        if (this != &other) { // 检查自赋值
            // 释放当前对象的资源
            if (data_) {
                std::free(data_);
            }

            // 转移资源所有权
            size_ = other.size_;
            data_ = other.data_;

            // 将原对象的数据指针置为空，避免重复释放
            other.size_ = 0;
            other.data_ = nullptr;

            std::cout << "Move assignment operator called" << std::endl;
        }
        return *this;
    }

    // 获取内存指针
    int* get() const {
        return data_;
    }

    // 检查内存是否申请成功
    bool is_valid() const {
        return data_ != nullptr;
    }

    // 禁止拷贝构造函数和拷贝赋值操作符
    RAIIMemory(const RAIIMemory&) = delete;
    RAIIMemory& operator=(const RAIIMemory&) = delete;

private:
    size_t size_;
    int* data_;
};

int main() {
    // 创建一个 RAIIMemory 对象，申请内存
    RAIIMemory memory1(100); // 申请 100 个 int 大小的内存
    if (!memory1.is_valid()) {
        std::cerr << "Failed to allocate memory!" << std::endl;
        return 1;
    }

    // 使用移动构造函数
    RAIIMemory memory2 = std::move(memory1); // 将 memory1 的资源转移到 memory2
    std::cout << "Memory1 is valid after move? " << memory1.is_valid() << std::endl; // 输出 0
    std::cout << "Memory2 is valid after move? " << memory2.is_valid() << std::endl; // 输出 1

    // 使用移动赋值运算符
    RAIIMemory memory3(200); // 申请 200 个 int 大小的内存
    memory3 = std::move(memory2); // 将 memory2 的资源转移到 memory3
    std::cout << "Memory2 is valid after move? " << memory2.is_valid() << std::endl; // 输出 0
    std::cout << "Memory3 is valid after move? " << memory3.is_valid() << std::endl; // 输出 1

    return 0;
}
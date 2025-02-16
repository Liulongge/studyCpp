#include <iostream>
#include <cstdlib>
#include <cstring> // 用于 memcpy

class RAIIMemory {
public:
    // 工厂函数，返回 RAIIMemory 对象的指针
    static RAIIMemory* create(size_t size) {
        int* data = static_cast<int*>(std::malloc(size * sizeof(int)));
        if (!data) {
            return nullptr; // 内存申请失败，返回 nullptr
        }
        return new RAIIMemory(size, data); // 成功时返回对象指针
    }

    // 默认构造函数
    RAIIMemory() : size_(0), data_(nullptr) {}

    // 构造函数，申请内存
    explicit RAIIMemory(size_t size) : size_(size), data_(nullptr) {
        data_ = static_cast<int*>(std::malloc(size * sizeof(int)));
        if (!data_) {
            throw std::bad_alloc(); // 内存申请失败，抛出异常
        }
        std::cout << "Memory allocated of size " << size_ << std::endl;
    }

    // 析构函数，释放内存
    ~RAIIMemory() {
        if (data_) {
            std::free(data_);
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

    // 拷贝构造函数
    RAIIMemory(const RAIIMemory& other) : size_(other.size_), data_(nullptr) {
        if (other.data_) {
            data_ = static_cast<int*>(std::malloc(size_ * sizeof(int)));
            if (!data_) {
                throw std::bad_alloc(); // 内存申请失败，抛出异常
            }
            std::memcpy(data_, other.data_, size_ * sizeof(int)); // 深拷贝数据
            std::cout << "Copy constructor called" << std::endl;
        }
    }

    // 拷贝赋值运算符
    RAIIMemory& operator=(const RAIIMemory& other) {
        if (this != &other) { // 检查自赋值
            // 释放当前对象的资源
            if (data_) {
                std::free(data_);
            }

            // 深拷贝数据
            size_ = other.size_;
            if (other.data_) {
                data_ = static_cast<int*>(std::malloc(size_ * sizeof(int)));
                if (!data_) {
                    throw std::bad_alloc(); // 内存申请失败，抛出异常
                }
                std::memcpy(data_, other.data_, size_ * sizeof(int));
            } else {
                data_ = nullptr;
            }

            std::cout << "Copy assignment operator called" << std::endl;
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

private:
    // 私有构造函数，只能通过工厂函数调用
    RAIIMemory(size_t size, int* data) : size_(size), data_(data) {
        std::cout << "Memory allocated of size " << size_ << std::endl;
    }

    size_t size_;
    int* data_;
};

int main() {
    // 使用工厂函数创建对象
    RAIIMemory* memory1 = RAIIMemory::create(100); // 申请 100 个 int 大小的内存
    if (!memory1) {
        std::cerr << "Failed to allocate memory!" << std::endl;
        return 1;
    }

    // 使用移动构造函数
    RAIIMemory memory2 = std::move(*memory1); // 将 memory1 的资源转移到 memory2
    std::cout << "Memory1 is valid after move? " << memory1->is_valid() << std::endl; // 输出 0
    std::cout << "Memory2 is valid after move? " << memory2.is_valid() << std::endl; // 输出 1

    // 使用拷贝构造函数
    RAIIMemory memory3 = memory2; // 深拷贝 memory2 到 memory3
    std::cout << "Memory2 is valid after copy? " << memory2.is_valid() << std::endl; // 输出 1
    std::cout << "Memory3 is valid after copy? " << memory3.is_valid() << std::endl; // 输出 1

    // 使用移动赋值运算符
    RAIIMemory memory4;
    memory4 = std::move(memory3); // 将 memory3 的资源转移到 memory4
    std::cout << "Memory3 is valid after move? " << memory3.is_valid() << std::endl; // 输出 0
    std::cout << "Memory4 is valid after move? " << memory4.is_valid() << std::endl; // 输出 1

    // 使用拷贝赋值运算符
    RAIIMemory memory5;
    memory5 = memory4; // 深拷贝 memory4 到 memory5
    std::cout << "Memory4 is valid after copy? " << memory4.is_valid() << std::endl; // 输出 1
    std::cout << "Memory5 is valid after copy? " << memory5.is_valid() << std::endl; // 输出 1

    // 释放对象
    delete memory1;

    return 0;
}
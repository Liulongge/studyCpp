#include <iostream>
#include <string>
#include <memory_resource>
#include <vector>

class MyClass {
public:
    MyClass(int x, const std::pmr::string& s) : x(x), s(s) {}
private:
    int x;
    std::pmr::string s;
};

int main() {
    // 使用 unsynchronized_pool_resource 替代 monotonic_buffer_resource
    std::pmr::unsynchronized_pool_resource pool;
    std::pmr::vector<MyClass> vec{&pool};

    // 模拟高频 push 和 pop
    for (int i = 0; i < 10; ++i) {
        std::cout << "--- Iteration " << i << " ---" << std::endl;

        // 分配一个 PMR 字符串
        std::pmr::string str("hello_" + std::to_string(i), &pool);
        vec.emplace_back(i, str);  // 存入 vector

        // 打印当前内存使用情况（仅示例，实际需自定义 memory_resource 跟踪）
        std::cout << "After push_back: pool memory in use" << std::endl;

        // 移除对象
        vec.pop_back();
        std::cout << "After pop_back: memory returned to pool (reusable)" << std::endl;
    }

    return 0;
}
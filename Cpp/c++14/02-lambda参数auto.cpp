// lambda参数auto
// 在C++11中，lambda表达式参数需要使用具体的类型声明：
// auto f = [] (int a) { return a; }
// 在C++14中，对此进行优化，lambda表达式参数可以直接是auto：
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 auto 推导参数类型
    auto printNumber = [](auto num) {
        std::cout << num << " ";
    };

    // 应用 lambda 表达式
    std::for_each(numbers.begin(), numbers.end(), printNumber);
    std::cout << std::endl;

    return 0;
}

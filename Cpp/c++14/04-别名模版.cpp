// C++14 引入了别名模板（Alias Templates），它允许我们为复杂的类型定义一个更简洁的名字。
// 这不仅提高了代码的可读性，也使得代码更加易于维护。
// 别名模板可以用来简化模板参数、减少冗余代码，并且可以在不改变原有类型的情况下提供一个更容易理解的名字。

// 别名模板的作用
// 提高代码可读性：通过给复杂类型赋予有意义的名字，使代码更易读。
// 简化模板编程：对于涉及多个模板参数或嵌套模板的情况，别名模板能够显著简化代码结构。
// 避免重复：如果某个类型在多处使用，别名模板可以帮助避免重复书写相同的类型声明。

#include <iostream>
#include <vector>
#include <string>

// 定义一个别名模板 VecT，代表 std::vector<T>
template<typename T>
using VecT = std::vector<T>;

// 定义一个别名模板 StrVec，代表 std::vector<std::string>
using StrVec = VecT<std::string>;

int main() {
    // 使用别名模板 VecT 创建一个整数向量
    VecT<int> intVec = {1, 2, 3, 4, 5};
    
    // 使用别名模板 StrVec 创建一个字符串向量
    StrVec strVec = {"hello", "world"};

    // 打印整数向量中的元素
    for (const auto& num : intVec) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 打印字符串向量中的元素
    for (const auto& str : strVec) {
        std::cout << str << " ";
    }
    std::cout << "\n";

    return 0;
}
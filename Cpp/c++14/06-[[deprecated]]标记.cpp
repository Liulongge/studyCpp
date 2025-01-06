// 在 C++14 中，[[deprecated]] 是一个属性（attribute），用来标记那些不应该再被使用的函数、变量、类或枚举成员。
// 当编译器遇到使用了带有 [[deprecated]] 属性的实体时，它会发出警告信息，提示开发者该实体已经被弃用，建议寻找替代方案。
// 这种机制有助于代码库的维护者逐步淘汰旧的接口，同时给使用者足够的时间来调整自己的代码。

// [[deprecated]] 的作用
// 通知开发者：通过编译器警告提醒开发者某个功能已被弃用，鼓励他们更新代码以使用新的接口。
// 平滑过渡：为旧功能提供了一个逐渐被淘汰的过程，避免突然移除导致现有代码无法编译。
// 文档化变更：作为一种形式的内联文档，直接在代码中表明哪些部分正在被淘汰，帮助团队成员理解代码库的变化。

// 使用 [[deprecated]]
// 你可以将 [[deprecated]] 直接放在你想要标记为弃用的实体之前。
// 如果需要提供额外的信息，比如为什么弃用或者应该使用什么替代品，可以在括号内添加字符串：
// [[deprecated("Use new_function instead.")]]


// 当你编译这段代码时，你应该会看到关于 add 函数和 DEPRECATED_VAR 变量的警告信息。
// 具体的警告文本取决于你使用的编译器及其配置。例如，在 GCC 或 Clang 中，你可能会看到类似于以下的消息：
// warning: 'int add(int, int)' is deprecated: Use add_v2 instead. [-Wdeprecated-declarations]

#include <iostream>

// 标记为弃用的函数
[[deprecated("Use add_v2 instead.")]]
int add(int a, int b) {
    return a + b;
}

// 新的替代函数
int add_v2(int a, int b) {
    return a + b;
}

// 标记为弃用的变量
[[deprecated("This variable is no longer used.")]]
const int DEPRECATED_VAR = 42;

int main() {
    // 使用弃用的函数，这会导致编译器警告
    std::cout << "Using deprecated function: " << add(3, 5) << '\n';

    // 使用新的替代函数
    std::cout << "Using new function: " << add_v2(3, 5) << '\n';

    // 使用弃用的变量，这也可能会导致编译器警告
    std::cout << "Deprecated variable value: " << DEPRECATED_VAR << '\n';

    return 0;
}
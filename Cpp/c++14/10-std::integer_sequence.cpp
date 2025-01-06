#include <iostream>
#include <utility> // For std::integer_sequence and std::make_index_sequence

// 一个模板函数，打印出给定的整数序列
template <typename T, T... Ints>
void print_sequence(std::integer_sequence<T, Ints...>) {
    int unused[] = { (std::cout << Ints << " ", 0)... };
    static_cast<void>(unused); // 避免未使用变量的警告
    std::cout << "\n";
}

// 使用 make_index_sequence 创建一个 index_sequence 并调用 print_sequence
template <std::size_t N>
void print_sequence_up_to() {
    print_sequence(std::make_index_sequence<N>{});
}

int main() {
    // 打印从 0 到 4 的序列
    print_sequence_up_to<5>();

    // 直接使用 std::index_sequence
    print_sequence(std::index_sequence<3, 1, 4, 1, 5, 9>{});

    return 0;
}
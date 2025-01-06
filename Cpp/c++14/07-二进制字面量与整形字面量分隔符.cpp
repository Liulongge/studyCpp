// C++14 引入了二进制字面量（Binary Literals）和整型字面量分隔符（Digit Separators），这两项特性让代码更具可读性，
// 特别是在处理长串数字或需要明确表示二进制值的情况下。

// 整型字面量分隔符
// 为了提高长数字的可读性，C++14 允许使用单引号 ' 作为千位分隔符。
// 这些引号不会影响数值的实际意义，只用于视觉上的分离，使得数字更易于阅读。例如：
// long long bigNumber = 1'000'000'000; // 更容易识别为十亿

// Binary literal (0b1010) in decimal: 10
// Big number with digit separators: 1234567890
// Binary with separators (0b1010'0011'1100) in decimal: 2604
#include <iostream>

int main() {
    // 使用二进制字面量
    int binValue = 0b1010; // 十进制的 10
    std::cout << "Binary literal (0b1010) in decimal: " << binValue << '\n';

    // 使用整型字面量分隔符
    long long bigNumber = 1'234'567'890;
    std::cout << "Big number with digit separators: " << bigNumber << '\n';

    // 结合二进制字面量和分隔符
    int binaryWithSeparator = 0b1010'0011'1100; // 更容易阅读的二进制数
    std::cout << "Binary with separators (0b1010'0011'1100) in decimal: " << binaryWithSeparator << '\n';

    return 0;
}
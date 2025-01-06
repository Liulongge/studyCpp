// std::quoted 是 C++14 引入的一个辅助函数模板，位于 <iomanip> 头文件中。
// 它主要用于流操作（如 std::cin 和 std::cout），允许你在读取或写入字符串时自动添加或移除引号，并处理转义字符。
// 这在需要将字符串以特定格式保存到文件或者从文件中读取字符串时非常有用。

// std::quoted 的作用
// 自动加/去引号：当你向流中写入字符串时，std::quoted 会自动为字符串加上双引号；当从流中读取字符串时，它会自动去掉这些引号。
// 处理转义字符：如果字符串包含特殊字符（如换行符、制表符等），std::quoted 会在写入时将它们转换为相应的转义序列（例如，\n 表示换行），
// 并在读取时将这些转义序列转换回原始字符。


#include <iostream>
#include <iomanip> // 包含 std::quoted
#include <sstream> // 包含 std::stringstream
#include <string>

int main() {
    // 写入带引号和转义字符的字符串
    std::string originalStr = "Hello, \"World\" This is a test.";
    std::stringstream ss;

    ss << std::quoted(originalStr);
    std::cout << "After writing with std::quoted:\n" << ss.str() << '\n';

    // 读取带引号和转义字符的字符串
    std::string readStr;
    ss.seekg(0); // 返回流的开始位置
    ss >> std::quoted(readStr);

    std::cout << "After reading with std::quoted:\n" << readStr << '\n';

    return 0;
}
// g++ 00014-最长公共前缀.cpp -o demo -std=c++11

#include<iostream>
#include<string>
#include<vector>

// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
// 示例 1：
// 输入：strs = ["flower","flow","flight"]
// 输出："fl"

// 示例 2：
// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。


using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string prefix = strs[0];

        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) {
                break;
            }
        }
        return prefix;
    }

    // 从前往后比较两个字符串，获取其公共部分
    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size()); // 取字符串长度最小值
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index;
        }
        // string 需要截取的字符串
        // a 截取字符串的开始位置（注：当a等于0或1时，都是从第一位开始截取）
        // b 要截取的字符串的长度
        return str1.substr(0, index);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<string> s={"flower","flow","flight"};
    cout <<  "最长公共前缀为：" << solution.longestCommonPrefix(s) << endl;
    // cout << "罗马数字：" << s << "， 表示数字：" << solution.romanToInt(s) << endl;
    return 0;
}
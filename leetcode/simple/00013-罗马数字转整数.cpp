// g++ 00013-罗马数字转整数.cpp -o demo -std=c++11

#include<iostream>
#include<string>
#include<unordered_map>

// unordered_map：
// 优点： 因为内部实现了哈希表，因此其查找速度非常的快
// 缺点： 哈希表的建立比较耗费时间
// 适用处：对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map

// map
// 优点：有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作红黑树，内部实现一个红黑书使得map的很多操作在lgn的时间复杂度下就可以实现，因此效率非常的高
// 缺点： 空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红/黑性质，使得每一个节点都占用大量的空间
// 适用处：对于那些有顺序要求的问题，用map会更高效一些

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length(); // 获取字符串长度
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            // 如果左边数字小于右边数字，那么需要减去左边数字 -> 左边数字按负数处理
            // 如果左边数字大于右边数字，那么按照整数处理 -> 左边数按整数处理
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }

private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};

int main(int argc, char *argv[])
{
    Solution solution;
    string s = "IV";//"MDCLXVI";
    cout << "罗马数字：" << s << "， 表示数字：" << solution.romanToInt(s) << endl;
    return 0;
}
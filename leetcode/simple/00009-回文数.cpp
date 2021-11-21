/*
 *给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
 *回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

 *示例 1：
 *输入：x = 121
 *输出：true

 *示例 2：
 *输入：x = -121
 *输出：false
 *解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

 *示例 3：
 *输入：x = 10
 *输出：false
 *解释：从右向左读, 为 01 。因此它不是一个回文数。

 *示例 4：
 *输入：x = -101
 *输出：false
 */

#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况：
        // 1. 当 x < 0 时，x 不是回文数, -12321 -> 12321-。
        // 2. 最后一位数为0, 10 -> 01
        // 3. 0是回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // 例子：1234321
        // x = 1234321
        // 通过取余处10运算，循环获取最后一位数字，然后对数字进行反转
        // 反转到位数相等(不满足条件)的时候（r=1234, x = 123）,退出整数反转
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 整数反转退出后，如果两数相等，或者revertedNumber/10（奇位数）与x相等，则是回文数
        // revertedNumber = 1234，x = 123
        return ((x == revertedNumber) || (x == revertedNumber / 10));
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int num = 1234321;
    if(solution.isPalindrome(1234321)){
        cout << num << ", 这是一个回文数" << endl;
    }
    else{
        cout << num << ", 这不是一个回文数" << endl;
    }
    return 0;
}
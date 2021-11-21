/*
 *给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 *如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 *假设环境不允许存储 64 位整数（有符号或无符号）。
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 2^31-1=2147483647,-2^31=-2147483648

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            // “截止到十位数 已经大于最大值”  或者  ”截止到十位数 等于最大值的十位数，且 个位数又大于个位数 7“
            if ((rev > (INT_MAX / 10)) || ((rev == INT_MAX / 10) && ((x % 10) > (INT_MAX % 10)))){
                return 0;
            }
            if ((rev < (INT_MIN / 10)) || ((rev == INT_MIN / 10) && ((x % 10) < (INT_MIN % 10)))){
                return 0;
            }

            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        return rev;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    cout << solution.reverse(-2147483646) << endl;
    return 0;
}
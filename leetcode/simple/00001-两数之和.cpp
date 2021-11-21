/*
 *给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 *你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 *你可以按任意顺序返回答案。

 *示例 1：
 *输入：nums = [2,7,11,15], target = 9
 *输出：[0,1]
 *解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {2,7,11,15};
    int target = 91;
    Solution solution;
    vector<int> result ;
    result = solution.twoSum(nums, target);
    // 使用迭代器进行结果打印
    if(result.size() == 0)
    {
        cout << "error" << endl;
    }
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
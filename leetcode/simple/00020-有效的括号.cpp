// g++ 00020-有效的括号.cpp -o demo -std=c++11

#include<iostream>
#include<string>
#include<stack>

using namespace std;
/*
 *给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *有效字符串需满足：
 *左括号必须用相同类型的右括号闭合。
 *左括号必须以正确的顺序闭合。

 *示例 1：
 *输入：s = "()"
 *输出：true

 *示例 2：
 *输入：s = "()[]{}"
 *输出：true

 *示例 3：
 *输入：s = "(]"
 *输出：false

 *示例 4：
 *输入：s = "([)]"
 *输出：false

 *示例 5：
 *输入：s = "{[]}"
 *输出：true
 */

class Solution {
public:
    bool isValid(string s) {
       if (s.length() % 2 != 0) {
           return false;
        }
        stack<char> stk;
        for(char c : s) {
            switch(c) {
                case '{' :
                case '(' :
                case '[' : stk.push(c); break; // 入栈
                case '}' : if (stk.empty() || stk.top() != '{') return false; else stk.pop(); break;
                case ']' : if (stk.empty() || stk.top() != '[') return false; else stk.pop(); break;
                case ')' : if (stk.empty() || stk.top() != '(') return false; else stk.pop(); break;
                default  : ;
            }
        }
        return stk.empty();
    }
};


int main(int argc, char *argv[])
{
    Solution solution;
    string s = {"{}()[]"};
    if(solution.isValid(s)) {
        cout << s << " -> 是有效的括号" << endl;
    }
    else {
        cout << s << " -> 不是有效的括号" << endl;
    }

    return 0;
}
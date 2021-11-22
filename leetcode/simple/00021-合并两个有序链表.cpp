// g++ 00020-有效的括号.cpp -o demo -std=c++11

#include<iostream>
#include<string>
#include<stack>

using namespace std;
/*
 *将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 *输入：l1 = [1,2,4], l2 = [1,3,4]
 *输出：[1,1,2,3,4,4]

 *示例 2：
 *输入：l1 = [], l2 = []
 *输出：[]

 *示例 3：
 *输入：l1 = [], l2 = [0]
 *输出：[0]
 */

struct ListNode
{
	int         m_Data;
	ListNode*   m_pNext;
	ListNode(int value,ListNode* next = NULL):m_Data(value),m_pNext(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
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
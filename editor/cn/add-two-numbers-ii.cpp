/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30104
 *
 * [445] 两数相加 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> s1,s2;
       ListNode *dummy=new ListNode(-1);
       ListNode *p=dummy;
       while (l1!=nullptr) {
         s1.push(l1->val);
         l1=l1->next;
       }
       while (l2!=nullptr) {
         s2.push(l2->val);
         l2=l2->next;
       }
       int carry=0;
       while (!s1.empty()||!s2.empty()||carry>0) {
        int val=carry;
         if (!s1.empty()) {
           val+=s1.top();
           s1.pop();
         }
         if (!s2.empty()) {
           val+=s2.top();
           s2.pop();
         }
         carry=val/10;
         val%=10;
         ListNode *tmp=new ListNode(val);
         tmp->next=p->next;
         p->next=tmp;
       }
       return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */


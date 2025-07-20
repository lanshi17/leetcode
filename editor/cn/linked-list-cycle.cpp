/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30104
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode *dummy=new ListNode(-1);
       dummy->next=head;
       ListNode *fast=dummy;
       ListNode *slow=dummy;
       while (fast!=nullptr&&fast->next!=nullptr) {
         slow=slow->next;
         fast=fast->next->next;
         if (slow==fast) {
           return true;
         }
       }
       return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */


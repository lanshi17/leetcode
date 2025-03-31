/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30104
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
       ListNode *fast=head;
       ListNode *slow=head;
       while (fast!=nullptr&&fast->next!=nullptr) {
         fast=fast->next->next;
         slow=slow->next;
         if (fast==slow) {
           break;
         }
       } 
       if (fast==nullptr||fast->next==nullptr) {
         return nullptr;
       }
       slow=head;
       while (slow!=fast) {
         slow=slow->next;
         fast=fast->next;
       }
       return slow;
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


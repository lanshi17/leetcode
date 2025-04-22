/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=30104
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) {
          return nullptr;
        }
        ListNode *fast=head,*slow=head;
        while (fast!=nullptr) {
          if (fast->val!=slow->val) {
            slow->next=fast;
            slow=slow->next;
          }
          fast=fast->next;
        }
        slow->next=nullptr;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */


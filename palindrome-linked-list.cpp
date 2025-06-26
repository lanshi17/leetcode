/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30201
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (head==nullptr||head->next==nullptr) {
          return true;
        }
        ListNode *slow,*fast;
        slow=fast=head;
        while (fast!=nullptr&&fast->next!=nullptr) {
          slow=slow->next;
          fast=fast->next->next;
        }
        if (fast!=nullptr) {
          slow=slow->next;
        }
        ListNode *left,*right;
        left=head;
        right=reverse(slow);
        while (right!=nullptr) {
          if (left->val!=right->val) {
            return false;
          }
          left=left->next;
          right=right->next;
        }
        return true;
    }
    ListNode* reverse(ListNode *head){
        ListNode *pre,*cur,*nxt;
        pre=nullptr;cur=head;nxt=head->next;
        while (cur!=nullptr) {
          cur->next=pre;
          pre=cur;
          cur=nxt;
          if (nxt!=nullptr) {
            nxt=nxt->next;
          }
        }
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */


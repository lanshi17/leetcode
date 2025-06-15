/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30201
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left==1) {
          return reverseN(head,right);
        }
        ListNode*pre=head;
        for (int i = 1; i < left-1; ++i) {
          pre=pre->next;
        }
        pre->next=reverseN(pre->next,right-left+1);
        return head;
    }
    ListNode* reverseN(ListNode*head,int n){
        ListNode *pre,*cur,*nxt;
        pre=nullptr;cur=head;nxt=head->next;
        while (n>0) {
          cur->next=pre;
          pre=cur;
          cur=nxt;
          if (nxt!=nullptr) {
            nxt=nxt->next;
          }
          n--;
        }
        head->next=cur;
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */


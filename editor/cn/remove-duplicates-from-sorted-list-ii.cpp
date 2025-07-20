/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30104
 *
 * [82] 删除排序链表中的重复元素 II
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
        ListNode *dummy1=new ListNode(-101);
        ListNode *dummy2=new ListNode(-101);
        ListNode *p=head,*p1=dummy1,*p2=dummy2;
        while (p!=nullptr) {
          if ((p->next!=nullptr&&p->val==p->next->val)||p->val==p1->val) {
            p1->next=p;
            p1=p1->next;
          }
          else
          {
            p2->next=p;
            p2=p2->next;
          }
          p=p->next;
          p1->next=nullptr;
          p2->next=nullptr;
        }
        return dummy2->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30104
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==nullptr||headB==nullptr) {
          return nullptr;
        }
        ListNode *p1=headA;
        ListNode *p2=headB;
        while (p1!=p2) {
          if (p1!=nullptr) {
            p1=p1->next;
          }else
          {
            p1=headB;
          }
          if (p2!=nullptr) {
            p2=p2->next;
          }else{
            p2=headA;
          }
        }
        return p1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */


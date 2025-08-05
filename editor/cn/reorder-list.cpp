/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30202
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode *p=head;
        while (p!=nullptr) {
          stk.push(p);
          p=p->next;
        }
        p=head;
        while (!stk.empty()) {
          ListNode *lastNode=stk.top();
          stk.pop();
          ListNode *nxt=p->next;
          if (lastNode==nxt||lastNode->next==nxt) {
            lastNode->next=nullptr;
            break;
          }
          p->next=lastNode;
          lastNode->next=nxt;
          p=nxt;
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */


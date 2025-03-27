/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30104
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
          return nullptr;
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *p=dummy;
        auto cmp=[](ListNode *a,ListNode *b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        for (const auto& head : lists) {
          if (head!=nullptr) {
            pq.push(head);
          }
        }
        while (!pq.empty()) {
          ListNode *node=pq.top();
          pq.pop();
          p->next=node;
          if (node->next!=nullptr) {
            pq.push(node->next);
          }
          p=p->next;
        }
        return dummy->next; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */


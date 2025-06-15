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
        return mergeKLists3(lists,0,lists.size()-1); 
    }
    ListNode* mergeKLists3(vector<ListNode*>& lists,int start,int end){
      if (start==end) {
        return lists[start];
      }
      int mid=start+(end-start)/2;
      ListNode* left =mergeKLists3(lists,start,mid);
      ListNode* right=mergeKLists3(lists,mid+1,end);
      return mergeKTwoLists(left,right);
    }
    ListNode* mergeKTwoLists(ListNode* l1,ListNode* l2){
      ListNode dummy(-1),*p=&dummy;
      ListNode*p1=l1,*p2=l2;
      while (p1!=nullptr&&p2!=nullptr) {
        if (p1->val>p2->val) {
          p->next=p2;
          p2=p2->next;
        }else
        {
          p->next=p1;
          p1=p1->next;
        }
        p=p->next;
      }
      if (p1!=nullptr) {
        p->next=p1;
      }
      if (p2!=nullptr) {
        p->next=p2;
      }
      return dummy.next;
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


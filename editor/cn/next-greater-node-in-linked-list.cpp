/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 * @lcpr version=30202
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode* head) {
       vector<int> nums;
       for(ListNode *p=head;p!=nullptr;p=p->next){
        nums.push_back(p->val);
       }
       vector<int> res(nums.size());
       stack<int> stk;
       for (int i = nums.size() - 1; i >= 0; i--)
       {
        while (!stk.empty()&&stk.top()<=nums[i]) {
          stk.pop();
        }
        res[i]=stk.empty()?0:stk.top();
        stk.push(nums[i]);
       }
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,4,3,5]\n
// @lcpr case=end

 */


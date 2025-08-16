/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30202
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       if (nums.empty()||k==0) {
         return {};
       } 
       vector<int> res;
       deque<int> dq;
       for (int i = 0; i < nums.size(); ++i) {
         while (!dq.empty()&&dq.front()<=i-k) {
           dq.pop_front();
         }
         while (!dq.empty()&&nums[dq.back()]<nums[i]) {
           dq.pop_back();
         }
         dq.push_back(i);
         if (i>=k-1) {
           res.push_back(nums[dq.front()]);
         }
       }
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */


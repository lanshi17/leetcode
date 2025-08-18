/*
 * @lc app=leetcode.cn id=918 lang=cpp
 * @lcpr version=30202
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int n=nums.size();
       vector<int> preSum(2*n+1,0);
       deque<int> dq;
       int res=nums[0];
       for (int i = 0; i < 2*n; ++i) {
         preSum[i+1]=preSum[i]+nums[i%n];
       } 
       for (int i = 0; i <=2*n; ++i) {
         while (!dq.empty()&&(i-dq.front())>n) {
           dq.pop_front();
         }
         if (!dq.empty()) {
           res=max(res,preSum[i]-preSum[dq.front()]);
         }
         while (!dq.empty()&&preSum[dq.back()]>=preSum[i]) {
           dq.pop_back();
         }
         dq.push_back(i);
       }
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-2,3,-2]\n
// @lcpr case=end

// @lcpr case=start
// [5,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2,2,-3]\n
// @lcpr case=end

 */


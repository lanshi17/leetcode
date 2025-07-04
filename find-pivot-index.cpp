/*
 * @lc app=leetcode.cn id=724 lang=cpp
 * @lcpr version=30201
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n=nums.size();
       vector<int> preSum(n+1,0);
       for (int i = 1; i <= n; ++i) {
         preSum[i]=preSum[i-1]+nums[i-1];
       } 
       for (int i = 1; i < preSum.size(); ++i) {
         int leftSum=preSum[i-1];
         int rightSum=preSum[n]-preSum[i];
         if (leftSum==rightSum) {
           return i-1;
         }
       }
       return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */


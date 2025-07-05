/*
 * @lc app=leetcode.cn id=523 lang=cpp
 * @lcpr version=30201
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int> preSum(n+1,0);
       for (int i = 1; i <= n; ++i) {
         preSum[i]=preSum[i-1]+nums[i-1];
       } 
       unordered_map<int,int>  valueIndexMap;
       for (int i = 0; i < preSum.size(); ++i) {
         int val=preSum[i]%k;
         if (!valueIndexMap.count(val)) {
           valueIndexMap[val]=i;
         }
       }
       for (int i = 1; i < preSum.size(); ++i) {
         int need=preSum[i]%k;
         if (valueIndexMap.count(need)) {
           if (i-valueIndexMap[need]>=2) {
             return true;
           }
         }
       }
       return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [23,2,4,6,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n13\n
// @lcpr case=end

 */


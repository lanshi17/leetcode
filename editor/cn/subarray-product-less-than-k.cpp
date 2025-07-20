/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=30201
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int left=0,right=0;
       int windowProduct=1;
       int count=0;
       while (right<nums.size()) {
         windowProduct*=nums[right++];
         while (windowProduct>=k&&left<right) {
           windowProduct/=nums[left++];
         }
         count+=right-left;
       } 
       return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */


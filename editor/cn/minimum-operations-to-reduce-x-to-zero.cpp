/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=30201
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int totalSum=0;
       for (auto& num : nums) {
         totalSum+=num;
       } 
       int target=totalSum-x;
       if (target==0) {
         return nums.size();
       }
       int maxLength=-1,currentSum=0,left=0,right=0;
       while(right < nums.size()) {
         currentSum+=nums[right++];
         while (currentSum>target&&left<right) {
           currentSum-=nums[left++];
         }
         if (currentSum==target) {
           maxLength=max(maxLength,right-left);
         }
       }
       return maxLength==-1?-1:nums.size()-maxLength;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

 */


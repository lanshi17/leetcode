/*
 * @lc app=leetcode.cn id=581 lang=cpp
 * @lcpr version=30202
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       if (nums.empty()) {
         return 0;
       } 
       int n=nums.size();
       int maxLeft=INT_MIN,minRight=INT_MAX;
       int left=-2,right=-1;//如果没有找到无序区间，left(-2) - right(-1) + 1 = -2 + 1 + 1 = 0
       for (int i = 0; i < n; ++i) {
         maxLeft=max(maxLeft,nums[i]);
         if (nums[i]<maxLeft) {
           left=i;
         }
         int j=n-1-i;
         minRight=min(minRight,nums[j]);
         if (nums[j]>minRight) {
           right=j;
         }
       }
       return left-right+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,6,4,8,10,9,15]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


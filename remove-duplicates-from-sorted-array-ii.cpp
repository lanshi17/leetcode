/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30201
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size()==0) {
         return 0;
       } 
       int slow=0,fast=0;
       int count=0;
       while (fast<nums.size()) {
         if (nums[fast]!=nums[slow]) {
           slow++;
           nums[slow]=nums[fast];
         }else if (slow<fast&&count<2)
         {
            slow++;
            nums[slow]=nums[fast];
         }
         fast++;
         count++;
         if (fast<nums.size()&&nums[fast]!=nums[fast-1]) {
           count=0;
         }
       }
       return slow+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */


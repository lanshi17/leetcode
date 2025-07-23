/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30201
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int left=0,right=nums.size()-1;
       while (left<=right) {
         int mid=left+(right-left)/2;
         if (nums[mid]<target) {
           left=mid+1;
         }else
         {
            right=mid-1;
         }
       } 
       return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */


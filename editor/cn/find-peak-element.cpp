/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=30201
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1;//连续函数的导数性质
        while (left<right) {
          int mid=left+(right-left)/2;
          if (nums[mid]>nums[mid+1]) {
            right=mid;
          }else
          {
            left=mid+1;
          }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */


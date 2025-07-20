/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30201
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while (left<=right) {
          int mid=left+(right-right)/2;
          if (nums[mid]==target) {
            return mid;
          }
          else if (nums[mid]>target)
          {
            right=mid-1; 
          }
          else left=mid+1;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */


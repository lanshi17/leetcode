/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30201
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {left_bound(nums,target),right_bound(nums,target)};
    }
    int left_bound(vector<int>&nums,int target){
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
        return (left>=0&&left<nums.size()&&nums[left]==target)?left:-1;

    }
    int right_bound(vector<int> &nums,int target){
        int left=0,right=nums.size()-1;
        while (left<=right) {
          int mid=left+(right-left)/2;
          if (nums[mid]>target) {
            right=mid-1;
          }else
          {
            left=mid+1;
          }
        }
        return (right>=0&&right<nums.size()&&nums[right]==target)?right:-1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

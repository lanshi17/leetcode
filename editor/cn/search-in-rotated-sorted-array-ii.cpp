/*
 * @lc app=leetcode.cn id=81 lang=cpp
 * @lcpr version=30202
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int left=0,right=nums.size()-1;
       while (left<=right) {
         while (left<right&&nums[left]==nums[left+1]) {
           left++;
         }
         while (left<right&&nums[right]==nums[right-1]) {
           right--;
         }
         int mid=left+(right-left)/2;
         if (nums[mid]==target) {
           return true;
         }
         if (nums[mid]>=nums[left]) {
           if (nums[left]<=target&&nums[mid]>target) {
             right=mid-1;
           }else
           {
            left=mid+1;
           }
         }else{
            if (nums[right]>=target&&nums[mid]<target) {
              left=mid+1;
            }else
            {
                right=mid-1;
            }
         }
       } 
       return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,6,0,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,5,6,0,0,1,2]\n3\n
// @lcpr case=end

 */


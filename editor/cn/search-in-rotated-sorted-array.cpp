/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30202
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left=0,right=nums.size()-1;
       while (left<=right) {
         int mid=left+(right-left)/2;
         if (nums[mid]==target) {
           return mid;
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
       return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */


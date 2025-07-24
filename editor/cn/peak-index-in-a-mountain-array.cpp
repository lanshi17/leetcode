/*
 * @lc app=leetcode.cn id=852 lang=cpp
 * @lcpr version=30202
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto nums=move(arr);
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
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,10,5,2]\n
// @lcpr case=end

 */


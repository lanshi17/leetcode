/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=30201
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n=nums.size();
       int left=0,right=0,count=0,res=0;
       while (right<n) {
         if (nums[right++]==1) {
           count++;
         }
         while (right-left-count>k) {
           if (nums[left++]==1) {
             count--;
           }
         }
         res=max(res,right-left);
       }
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */


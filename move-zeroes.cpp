/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30104
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int p=removeElement(nums,0);
       for(;p<nums.size();p++){
        nums[p]=0;
       } 
    }
    int removeElement(vector<int> &nums,int val){
        int fast=0,slow=0;
        while (fast<nums.size()) {
          if (nums[fast]!=val) {
            nums[slow]=nums[fast];
            slow++;
          }
          fast++;
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


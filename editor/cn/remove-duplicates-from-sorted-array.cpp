/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30104
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) {
          return 0;
        }
       int p1=0,p2=0;
       for (int i = 0; i < nums.size(); ++i) {
         if (nums[p1]!=nums[p2]) {
           p1++;
           nums[p1]=nums[p2];
         }
         p2++;
       } 
       return p1+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */


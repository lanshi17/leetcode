/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30104
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
          return 0;
        }
       int left=0,right=nums.size()-1;
       while (left<=right) {
         if (nums[left]==val) {
           nums[left]=nums[right--];
         }else
         {
            left++;
         }
       } 
       return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */


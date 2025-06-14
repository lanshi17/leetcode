/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30201
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0;
        for (int i = 0; i < n-1; i++)
        {
            farthest=max(farthest,i+nums[i]);
            if (farthest<=i){
              return false;
            }
        }
        return farthest>=n-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */


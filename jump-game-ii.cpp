/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30201
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int end=0,farthest=0;
        int jumps=0;
        for (int i = 0; i < n-1; i++)
        {
            farthest=max(nums[i]+i,farthest);
            if (end==i) {
              jumps++;
              end=farthest;
            }
        }
        return jumps;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */


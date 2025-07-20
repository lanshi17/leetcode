/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30201
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    int trackSum=0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target);
        return res;
    }
    void backtrack(vector<int>& nums,int start,int target){
        if (trackSum==target) {
          res.push_back(track);
          return;
        }
        if (trackSum>target) {
          return;
        }
        for (int i = start; i < nums.size(); ++i) {
          if (i>start&&nums[i]==nums[i-1]) {
            continue;
          }
          track.push_back(nums[i]);
          trackSum+=nums[i];
          backtrack(nums,i+1,target);
          track.pop_back();
          trackSum-=nums[i];
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */


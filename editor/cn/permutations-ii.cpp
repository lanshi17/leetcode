/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30201
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        used=vector<bool>(nums.size(),false);
        backtrack(nums);
        return res;

    }
    void backtrack(vector<int>& nums){
        if (track.size()==nums.size()) {
          res.push_back(track);
          return;
        }
        for (int i = 0; i < nums.size(); ++i) {
          if (used[i]) {
            continue;
          }
          if (i>0&&nums[i]==nums[i-1]&&used[i-1]) {
            continue;
          }
          track.push_back(nums[i]);
          used[i]=true;
          backtrack(nums);
          track.pop_back();
          used[i]=false;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */


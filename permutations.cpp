/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30201
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        vector<bool> used(nums.size(),false);
        backtrace(nums,track,used);
        return res;
    }
    void backtrace(vector<int>&nums,vector<int>&track,vector<bool>&used){
        if (track.size()==nums.size()) {
            res.push_back(track);
          return;
        }
        for (int i = 0; i <nums.size(); i++)
        {
          if (used[i]) {
            continue;
          }   
          track.push_back(nums[i]);
          used[i]=true;
          backtrace(nums,track,used);
          track.pop_back();
          used[i]=false;

        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30201
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int>& nums,int start){
        res.push_back(vector<int>(track.begin(),track.end()));
        for (int i = start; i <nums.size(); ++i) {
          if (i>start&&nums[i]==nums[i-1]) {//剪枝
            continue;
          }
          track.push_back(nums[i]);
          backtrack(nums,i+1);
          track.pop_back();

        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


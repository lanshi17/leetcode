/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30201
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> subsets(vector<int>& nums) {
        backTrack(nums,0);
        return res;
    }
    void backTrack(vector<int>&nums,int start){
        res.push_back(track);
        for (int i = start; i < nums.size(); ++i) {
          track.push_back(nums[i]);
          backTrack(nums,i+1);
          track.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


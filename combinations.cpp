/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30201
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,k);
        return res;
    }
    void backtrack(int start,int n,int k){
        if (k==track.size()) {
          res.push_back(vector<int>(track.begin(),track.end()));
          return;
        }
        for (int i = start; i <=n; ++i) {
            track.push_back(i);
            backtrack(i+1,n,k);
            track.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */


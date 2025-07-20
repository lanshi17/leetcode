/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 * @lcpr version=30201
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int mn=m*n;
        k%=mn;
        vector<vector<int>> res(m,vector<int>(n));
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            int index=(i*n+j+k)%(mn);
            res[index/n][index%n]=grid[i][j];
          }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n9\n
// @lcpr case=end

 */


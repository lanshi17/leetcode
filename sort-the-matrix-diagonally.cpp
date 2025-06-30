/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30201
 *
 * [1329] 将矩阵按对角线排序
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       unordered_map<int,vector<int>> diagonals;
       int m=mat.size(),n=mat[0].size();
       for (int i = 0; i < m; i++)
       {
            for (int j = 0; j < n; ++j) {
                int diagonalsID=i-j;
                diagonals[diagonalsID].push_back(mat[i][j]);
            }
       } 
       for (auto& diagonal : diagonals) {
         sort(diagonal.second.begin(),diagonal.second.end(),greater<int>());
       }
       for (int i = 0; i < m; ++i) {
         for (int j = 0; j < n; ++j) {
           mat[i][j]=diagonals[i-j].back();
           diagonals[i-j].pop_back();
         }
       }
       return mat;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */


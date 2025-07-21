/*
 * @lc app=leetcode.cn id=240 lang=cpp
 * @lcpr version=30201
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m=matrix.size(),n=matrix[0].size();
       int i=0,j=n-1;
       while (i<m&&j>=0) {
         if (matrix[i][j]<target) {
           i++;
         }else if (matrix[i][j]>target)
         {
            j--;
         }else
         {
            return true;
         }
       } 
       return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n20\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30200
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n=matrix.size();
       for (int i = 0; i < n; i++)
       {
            for (int j = i; j < n; ++j) {
              int temp=matrix[i][j];
              matrix[i][j]=matrix[j][i];
              matrix[j][i]=temp;
            }
       } 
       for (auto& row : matrix) {
         reverse(row.begin(),row.end());
       }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */


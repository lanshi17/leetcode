/*
 * @lc app=leetcode.cn id=566 lang=cpp
 * @lcpr version=30201
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       int m=mat.size(),n=mat[0].size();
       if (r*c!=m*n) {
         return mat;
       } 
       vector<vector<int>> res(r,vector<int>(c));
       for (int i = 0; i < m*n; ++i) {
         set(res,i,get(mat,i));
       }
       return res;
    }
    int get(vector<vector<int>>& matrix,int index){
        int m=matrix.size(),n=matrix[0].size();
        int i=index/n,j=index%n;
        return matrix[i][j];
    }
    void set(vector<vector<int>>& matrix,int index,int value){
        int m=matrix.size(),n=matrix[0].size();
        int i=index/n,j=index%n;
        matrix[i][j]=value;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3,4]]\n1\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n2\n4\n
// @lcpr case=end

 */


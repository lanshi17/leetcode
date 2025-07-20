/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30201
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m=matrix.size(),n=matrix[0].size();
       int left=0,right=m*n-1;
       while (left<=right) {
         int mid=left+(right-left)/2;
         if (get(matrix,mid)<target) {
           left=mid+1;
         }else if (get(matrix,mid)>target)
         {
            right=mid-1;  
         }else
         {
            return true;
         }
       } 
       return false;
    }
    int get(vector<vector<int>> &matrix,int index){
        int n=matrix[0].size();
        int i=index/n,j=index%n;
        return matrix[i][j];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */


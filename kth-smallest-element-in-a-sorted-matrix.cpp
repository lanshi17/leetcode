/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=30104
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp=[](const vector<int> &a,const vector<int> &b){return a[0]>b[0];};
        std::priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        for (int i = 0; i < matrix.size(); ++i) {
          pq.push({matrix[i][0],i,0});
        }
        int res=-1;
        while (!pq.empty()&&k>0) {
          vector<int>  cur=pq.top();
          pq.pop();
          res=cur[0];
          k--;
          int i=cur[1],j=cur[2];
          if (j+1<matrix[i].size()) {
            pq.push({matrix[i][j+1],i,j+1});
          }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */


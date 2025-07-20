/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 * @lcpr version=30201
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
       int preSum=0,res=0,n=hours.size();
       unordered_map<int,int> valToIndex;
       for (int i = 0; i < n; ++i) {
         preSum+=(hours[i]>8?1:-1);
         if (preSum>0) {
           res=max(res,i+1);
         }else
         {
            if (!valToIndex.count(preSum)) {
              valToIndex[preSum]=i;
            }
            if (valToIndex.count(preSum-1)) {
              res=max(res,i-valToIndex[preSum-1]);
            }
         }
       }
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,9,6,0,6,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6]\n
// @lcpr case=end

 */


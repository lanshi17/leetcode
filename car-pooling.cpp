/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=30201
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxStop=0;
        for (const auto& trip : trips) {
          maxStop=max(maxStop,trip[2]);
        }
       vector<int> res(maxStop+1,0);
       for (const auto& trip : trips) {
         int from = trip[1];
         int to = trip[2];
         int culNum=trip[0];
         res[from]+=culNum;
         if (to<maxStop+1) {
           res[to]-=culNum;
         }
       } 
       int culCapcity=0;
       for (int i = 0; i <= maxStop; ++i) {
         culCapcity+=res[i];
         if (culCapcity>capacity) {
           return false;
         }
       }
       return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */


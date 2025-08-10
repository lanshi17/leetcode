/*
 * @lc app=leetcode.cn id=2073 lang=cpp
 * @lcpr version=30202
 *
 * [2073] 买票需要的时间
 */

// @lc code=start
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       int res=0;
       for (int i = 0; i < tickets.size(); ++i) {
         if (i<=k) {
           res+=min(tickets[k],tickets[i]);
         }else
         {
            res+=min(tickets[k]-1,tickets[i]);
         }
       } 
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,1]\n0\n
// @lcpr case=end

 */


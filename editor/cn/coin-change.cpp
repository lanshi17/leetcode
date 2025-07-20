/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30201
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        memo=vector<int>(amount+1,-2);
        return dp(coins,amount);
    }
    int dp(vector<int>&coins,int amount){
        if (amount==0) {
          return 0;
        }
        if (amount<0) {
          return -1;
        }
        if (memo[amount]!=-2) {
          return memo[amount];
        }
        int res=INT_MAX;
        for (const auto& coin : coins) {
          int subProblem=dp(coins,amount-coin);
          if (subProblem==-1) {
            continue;
          }
          res=min(res,subProblem+1);
        }
        memo[amount]=(res==INT_MAX)?-1:res;
        return memo[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */


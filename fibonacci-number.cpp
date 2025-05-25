/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30201
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        vector<int> memo(n+1,-1);
        return dp(memo,n);
    }
    int dp(vector<int> &memo,int n){
        if (n==0||n==1) {
          return n;
        }
        if (memo[n]!=-1) {
          return memo[n];
        }
        memo[n]=dp(memo,n-1)+dp(memo,n-2);
        return memo[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */


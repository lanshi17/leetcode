/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 * @lcpr version=30202
 *
 * [1696] 跳跃游戏 VI
 */

// @lc code=start
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
       int n=nums.size();
       vector<long long>dp(n,INT_MIN);
       dp[0]=nums[0];
       deque<int> dq;
       dq.push_back(0);
       for (int i = 1; i < n; ++i) {
         while (!dq.empty()&&dq.front()<(i-k)) {
            dq.pop_front();
         }
         dp[i]=dp[dq.front()]+nums[i];
         while (!dq.empty()&&dp[dq.back()]<=dp[i]) {
           dq.pop_back();
         }
         dq.push_back(i);
       }  
       return static_cast<int>(dp[n-1]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-1,-2,4,-7,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [10,-5,-2,4,0,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,-5,-20,4,-1,3,-6,-3]\n2\n
// @lcpr case=end

 */


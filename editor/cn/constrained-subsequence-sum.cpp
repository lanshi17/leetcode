/*
 * @lc app=leetcode.cn id=1425 lang=cpp
 * @lcpr version=30202
 *
 * [1425] 带限制的子序列和
 */

// @lc code=start
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<int> dq;
        int res=INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            // 移除超出跳跃范围的索引
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            
            // 当前位置的最大得分 = 前面k步范围内最大得分 + 当前位置值
            dp[i] = nums[i];
            if (!dq.empty()) {
              dp[i]=max(dp[i],dp[dq.front()]+nums[i]);
            }
            res=max(res,dp[i]);
            // 维护队列单调性，保持队列中dp值递减
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            
            if (dp[i]>0) {
              dq.push_back(i);
            }
        }
        
        return res; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,2,-10,5,20]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [10,-2,-10,-5,20]\n2\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=862 lang=cpp
 * @lcpr version=30202
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       int n=nums.size();
       vector<long long>preSum(n+1,0);
       deque<int> dq;
       int res=INT_MAX;
       for (int i = 0; i <n; ++i) {
         preSum[i+1]=preSum[i]+nums[i];
       } 
       for (int i = 0; i <=n; ++i) {
         while (!dq.empty()&&preSum[i]-preSum[dq.front()]>=k) {
           res=min(res,i-dq.front());
           dq.pop_front();
         }
         while (!dq.empty()&&preSum[dq.back()]>=preSum[i]) {
           dq.pop_back();
         }
         dq.push_back(i);
       }
       return res<=n?res:-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,2]\n3\n
// @lcpr case=end

 */


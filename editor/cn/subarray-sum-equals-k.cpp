/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30201
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int preSum=0,res=0;
       unordered_map<int,int> count;
       count[0]=1;
       int n=nums.size();
       for (int i = 1; i <= n; ++i) {
         preSum+=nums[i-1];
         int need=preSum-k;
         if (count.find(need)!=count.end()) {
           res+=count[need];
         }
         count[preSum]++;
       }
       return res; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */


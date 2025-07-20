/*
 * @lc app=leetcode.cn id=974 lang=cpp
 * @lcpr version=30201
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int n=nums.size();
       int preSum=0,res=0;
       unordered_map<int,int> count;
       count[0]=1;
       for (int i = 1; i <= n; ++i) {
            preSum+=nums[i-1];
            int need=preSum%k;
            if (need<0) {
                need+=k;
            }
            if (count.find(need)!=count.end())
            {
                res+=count[need];
            }
            count[need]++;
        }
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,0,-2,-3,1]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5]\n9\n
// @lcpr case=end

 */


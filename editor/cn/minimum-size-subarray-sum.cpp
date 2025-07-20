/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30201
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0;
        int window = 0, res = __INT_MAX__;
        while (right < nums.size())
        {
            window += nums[right++];
            while (window >= target && left < right)
            {
                res = min(res, right - left);
                window -= nums[left++];
            }
        }
        return res == __INT_MAX__ ? 0 : res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * @lcpr version=30201
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        int left = 0, right = 0;
        set<long> window;
        while (right < nums.size())
        {
            auto ceiling = window.lower_bound((long)nums[right]); // 使用 lower_bound 查找第一个不小于给定值的元素
            if (ceiling != window.end() && *ceiling - nums[right] <= valueDiff)
            {
                return true;
            }
            auto floor = ceiling;
            if (floor != window.begin())
            {
                floor--;
                if (nums[right] - *floor <= valueDiff)
                {
                    return true;
                }
            }
            window.insert(nums[right++]);
            if (right - left > indexDiff)
            {
                window.erase(nums[left++]);
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */

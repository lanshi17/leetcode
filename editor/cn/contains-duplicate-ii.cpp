/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30201
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        unordered_set<int> window;
        while (right < nums.size())
        {
            if (window.count(nums[right]))
            {
                return true;
            }
            window.insert(nums[right++]);
            if (right - left > k)
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
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */

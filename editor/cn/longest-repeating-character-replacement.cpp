/*
 * @lc app=leetcode.cn id=424 lang=cpp
 * @lcpr version=30201
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length(), left = 0, right = 0, res = 0, maxCount;
        vector<int> charCount(26, 0);
        while (right < n)
        {
            int c = s[right++] - 'A';
            charCount[c]++;
            maxCount = max(maxCount, charCount[c]);
            if (right - left - maxCount > k)
            {
                charCount[s[left++] - 'A']--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ABAB"\n2\n
// @lcpr case=end

// @lcpr case=start
// "AABABBA"\n1\n
// @lcpr case=end

 */

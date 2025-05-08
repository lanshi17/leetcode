/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30200
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 处理边界条件
        if (s.empty() || t.empty() || (s.size() < t.size()))
        {
            return "";
        }
        // 记录 t 中每个字符的需求量
        unordered_map<char, int> need,window;
        for (char c : t)
        {
            need[c]++;
        }
        // 初始化滑动窗口的左右边界
        int left = 0, right = 0;
        // 记录当前窗口中满足需求的字符数量
        int valid = 0;
        // 记录最小子串的起始位置和长度
        int start = 0, len = INT_MAX;
        // 滑动窗口右边界移动
        while (right < s.size())
        {
            char c = s[right];
            right++;
            // 如果当前字符在 need 中，则更新窗口中的字符计数
            if (need.count(c))
            {
                window[c]++;
                // 如果窗口中该字符的数量满足需求，则 valid 增加
                if (window[c] == need[c])
                {
                    valid++;
                }
            }
            // 当窗口中的字符数量满足 t 中所有字符的需求时，尝试收缩窗口
            while (valid == need.size())
            {
                // 更新最小子串的起始位置和长度
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                // 如果移出的字符在 need 中，则更新窗口中的字符计数
                if (need.count(d))
                {
                    // 如果窗口中该字符的数量不再满足需求，则 valid 减少
                    if (window[d] == need[d])
                    {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        // 如果没有找到符合条件的子串，返回空字符串
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

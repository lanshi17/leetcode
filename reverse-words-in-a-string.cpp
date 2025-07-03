/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30201
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return s;
        }

        string cleanedString;
        cleanedString.reserve(s.size()); // 预分配内存

        bool inWord = false;
        for (char ch : s) {
            if (std::isspace(ch)) {
                if (inWord) {
                    cleanedString += ' ';
                    inWord = false;
                }
            } else {
                cleanedString += ch;
                inWord = true;
            }
        }

        // 去除末尾的空格
        if (!cleanedString.empty() && cleanedString.back() == ' ') {
            cleanedString.pop_back();
        }

        // 反转整个字符串
        std::reverse(cleanedString.begin(), cleanedString.end());

        // 反转每个单词
        int wordStart = 0;
        int n = cleanedString.length();
        for (int i = 0; i <= n; ++i) {
            if (i == n || cleanedString[i] == ' ') {
                std::reverse(cleanedString.begin() + wordStart, cleanedString.begin() + i);
                wordStart = i + 1;
            }
        }

        return cleanedString;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */


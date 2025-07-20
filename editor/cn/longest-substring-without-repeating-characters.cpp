/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30201
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int left=0,right=0,res=0;
       unordered_map<char,int>window;
       while (right<s.size()) {
         char c=s[right++];
         window[c]++;
         while (window[c]>1) {
           char d=s[left++];
           window[d]--;
         }
         res=max(res,right-left);
       } 
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */


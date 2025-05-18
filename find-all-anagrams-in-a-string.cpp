/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30201
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> res;
       unordered_map<char,int>need,window;
       int right=0,left=0,valid=0;
       for (const auto& t : p) {
         need[t]++;
       } 
       while (right<s.size()) {
         char c=s[right++];
         if (need.count(c)) {
           window[c]++;
           if (window[c]==need[c]) {
             valid++;
           }
         }
         while ((right-left)>=p.size()) {
           if (valid==need.size()) {
             res.push_back(left);
           }
           char d=s[left++];
           if (need.count(d)) {
             if (window[d]==need[d]) {
               valid--;
             }
             window[d]--;
           }
         }
       }

       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */


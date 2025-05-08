/*
 * @lc app=leetcode.cn id=567 lang=cpp
 * @lcpr version=30200
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty() || s2.empty() || (s2.size() < s1.size()))
        {
            return false;
        }
        unordered_map<char,int>need,window;
       for (const auto& c : s1) {
         need[c]++;
       } 
       int left=0,right=0,valid=0;
       while (right<s2.size()) {
         char c=s2[right++];
         if (need.count(c)) {
            window[c]++;
           if (window[c]==need[c]) {
             valid++;
           }
         }
         while ((right-left)>=s1.size()) {
            if (valid==need.size()) {
              return true;
            }
           char d=s2[left++];
           if (need.count(d)) {
             if (window[d]==need[d]) {
               valid--;
             }
             window[d]--;
           }
         }
       }
       return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */


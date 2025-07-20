/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30104
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
       string res,s1,s2;
       for (int i = 0; i < s.length(); ++i) {
         s1=palindrome(s,i,i);//奇数长度
         s2=palindrome(s,i,i+1);//偶数长度
         res=res.length()>s1.length()?res:s1;
         res=res.length()>s2.length()?res:s2;
       }
       return res;
    }
private:
    string palindrome(string s,int l,int r){
        while (l>=0&&r<s.length()&&s[l]==s[r]) {
          l--;
          r++;
        }
        return s.substr(l+1,r-l-1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */


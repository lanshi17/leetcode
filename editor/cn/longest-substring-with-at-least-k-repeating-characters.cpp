/*
 * @lc app=leetcode.cn id=395 lang=cpp
 * @lcpr version=30201
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int len=0;
        for (int i = 1; i <=26; ++i) {
          len=max(len,longestKLetterSubstr(s,k,i));
        }
        return len;
    }
    int longestKLetterSubstr(string s,int k,int count){
        int res=0,left=0,right=0;
        array<int,26> windowCount={0};
        int uniqueCount=0,validCount=0;
        while (right<s.size()) {
          char c=s[right++];
          if (windowCount[c-'a']==0) {
            uniqueCount++;
          }
          windowCount[c-'a']++;
          if (windowCount[c-'a']==k) {
            validCount++;
          }
          while (uniqueCount>count) {
            char d=s[left++];
            if (windowCount[d-'a']==k) {
              validCount--;
            }
            windowCount[d-'a']--;
            if (windowCount[d-'a']==0) {
              uniqueCount--;
            }
          }
          if (validCount==count) {
            res=max(res,right-left);
          }
        }
        return res;

    }
};
// @lc code=end

/*
// @lcpr case=start
// "aaabb"\n3\n
// @lcpr case=end

// @lcpr case=start
// "ababbc"\n2\n
// @lcpr case=end

 */

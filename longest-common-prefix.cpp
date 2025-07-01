/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30201
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int n=strs[0].length();
       int m=strs.size();
       for (int col = 0; col < n; ++col) {
         for (int row = 1; row < m; ++row) {
           string thisStr=strs[row],preStr=strs[row-1];
           if (col>=thisStr.length()||col>=preStr.length()||thisStr[col]!=preStr[col]) {
             return strs[row].substr(0,col);
           }
         }
       }
       return strs[0];

    }
};
// @lc code=end



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */


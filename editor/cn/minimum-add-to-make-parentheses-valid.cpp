/*
 * @lc app=leetcode.cn id=921 lang=cpp
 * @lcpr version=30202
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
       int res=0,need=0;
       for (int i = 0; i < s.size(); ++i) {
         if (s[i]=='(') {
           need++;
         }
         if (s[i]==')') {
           need--;
           if (need==-1) {
             need=0;
             res++;
           }
         }
       } 
       return res+need;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "((("\n
// @lcpr case=end

 */


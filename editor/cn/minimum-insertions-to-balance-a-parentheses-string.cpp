/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 * @lcpr version=30202
 *
 * [1541] 平衡括号字符串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
       int res=0,need=0;
       for (int i = 0; i < s.size(); ++i) {
         if (s[i]=='(') {
           need+=2;
           if (need%2) {
             res++;need--;
           }
         }
         if (s[i]==')') {
           need--;
           if (need==-1) {
             res++;
             need=1;
           }
         }
       } 
       return res+need;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()))"\n
// @lcpr case=end

// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "))())("\n
// @lcpr case=end

// @lcpr case=start
// "(((((("\n
// @lcpr case=end

// @lcpr case=start
// ")))))))"\n
// @lcpr case=end

 */


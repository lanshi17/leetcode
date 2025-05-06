/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30104
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
       int left=0,right=s.size()-1;
       while (left<right) {
         char temp=s[left];
         s[left]=s[right];
         s[right]=temp;
         right--;
         left++;
       } 
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30201
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
       s=[&s]()->string
       {
            string sb;
            for (const auto& ch : s) {
                if (isalnum(ch)) {
                    sb+=tolower(ch);
                }
                
            } 
            return sb;
        }();
        //std::cout << s << std::endl;
        int left=0,right=s.length()-1;
        while (left<right) {
          if (s[left]!=s[right]) {
            return false;
          }
          left++;
          right--;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=402 lang=cpp
 * @lcpr version=30202
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<char> s;
       for(auto c : num)
       {
        while (!s.empty()&&s.top()>c&&k>0) {
          s.pop();
          --k;
        }
        if (s.empty()&&c=='0') {
         continue;
        }
        s.push(c);
       } 
       while (!s.empty()&&k>0) {
         s.pop();
         --k;
       }
       if (s.empty()) {
         return "0";
       }
       string res;
       while (!s.empty()) {
         res+=s.top();
         s.pop();
       }
       reverse(res.begin(),res.end());
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1432219"\n3\n
// @lcpr case=end

// @lcpr case=start
// "10200"\n1\n
// @lcpr case=end

// @lcpr case=start
// "10"\n2\n
// @lcpr case=end

 */


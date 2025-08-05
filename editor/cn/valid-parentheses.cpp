/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30202
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for (const auto c : s) {
          if (c=='{'||c=='['||c=='(') {
            left.push(c);
          }else
          {
            if (!left.empty()&&leftOf(c)==left.top()) {
              left.pop();
            }else{
                return false;
            }
          }
        }
        return left.empty();
    }
private:
    char leftOf(char c){
        if (c=='}') {
          return '{';
        }
        if (c==')') {
          return '(';
        }
        return '[';
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */


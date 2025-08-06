/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30202
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> stk;
       for (const auto& token : tokens) {
         if (token=="/"||token=="+"||token=="-"||token=="*") {
           int a=stk.top();
           stk.pop();
           int b=stk.top();
           stk.pop();
           switch (token[0])
           {
            case '+':
                stk.push(a+b);
                break;
            case '-':
                stk.push(b-a);
                break;
            case '*':
                stk.push(a*b);
                break;
            case '/':
                stk.push(b/a);
                break;
           }
         }else
         {
            stk.push(stoi(token));
         }
       } 
       return stk.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */


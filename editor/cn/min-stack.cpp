/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30202
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    MinStack()=default;
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty()||val<=minStk.top()) {
          minStk.push(val);
        }
    }
    
    void pop() {
        if (minStk.top()==stk.top()) {
          minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
private:
    stack<int> stk;
    stack<int> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */


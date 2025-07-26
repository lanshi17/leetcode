/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30202
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x); 
    }
    
    int pop() {
        peek();
        int topElement=s2.top();
        s2.pop();
        return topElement;
    }
    
    int peek() {
        if (s2.empty()) {
          while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
          }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
private:
    stack<int> s1,s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"]\n[[], [1], [2], [], [], []]\n
// @lcpr case=end

 */


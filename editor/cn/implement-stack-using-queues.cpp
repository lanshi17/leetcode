/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30202
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        top_elem=x;
    }
    
    int pop() {
        int size=q.size();
        while (size>2) {
          q.push(q.front());
          q.pop();
          size--;
        }
        top_elem=q.front();
        q.push(q.front());
        q.pop();
        int result=q.front();
        q.pop();
        return result;
    }
    
    int top() {
        return top_elem;
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
    int top_elem=0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"]\n[[], [1], [2], [], [], []]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=LCR 184 lang=cpp
 * @lcpr version=30202
 *
 * [LCR 184] 设计自助结算系统
 */

// @lc code=start
class Checkout
{
public:
    Checkout()
    {
    }

    int get_max()
    {
        if(dq.empty()){
            return -1;
        }
        return dq.front();
    }

    void add(int value)
    {
        q.push(value);
        while (!dq.empty()&&dq.back()<value) {
          dq.pop_back();
        }
        dq.push_back(value);
    }

    int remove()
    {
        if (q.empty()) {
          return -1;
        }
        int top=q.front();
        q.pop();
        if (top==dq.front()) {
          dq.pop_front();
        }
        return top;
    }

private:
    deque<int> dq;
    queue<int> q;
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */
// @lc code=end

/*
// @lcpr case=start
// ["Checkout","add","add","get_max","remove","get_max"]\n[[],[4],[7],[],[],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["Checkout","remove","get_max"]\n[[],[],[]]\n
// @lcpr case=end

 */

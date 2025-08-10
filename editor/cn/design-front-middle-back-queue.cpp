/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 * @lcpr version=30202
 *
 * [1670] 设计前中后队列
 */

// @lc code=start
class FrontMiddleBackQueue {
private:
    std::deque<int> q;

public:
    /** 初始化队列 */
    FrontMiddleBackQueue() {}
    
    /** 将 val 添加到队列的 最前面 */
    void pushFront(int val) {
        q.push_front(val);
    }
    
    /** 将 val 添加到队列的 正中间 */
    void pushMiddle(int val) {
        int mid = q.size() / 2;
        q.insert(q.begin() + mid, val);
    }
    
    /** 将 val 添加到队里的 最后面 */
    void pushBack(int val) {
        q.push_back(val);
    }
    
    /** 将 最前面 的元素从队列中删除并返回值 */
    int popFront() {
        if (q.empty()) {
            return -1;
        }
        int val = q.front();
        q.pop_front();
        return val;
    }
    
    /** 将 正中间 的元素从队列中删除并返回值 */
    int popMiddle() {
        if (q.empty()) {
            return -1;
        }
        int mid = (q.size() - 1) / 2;
        int val = q[mid];
        q.erase(q.begin() + mid);
        return val;
    }
    
    /** 将 最后面 的元素从队列中删除并返回值 */
    int popBack() {
        if (q.empty()) {
            return -1;
        }
        int val = q.back();
        q.pop_back();
        return val;
    }
};


/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end



/*
// @lcpr case=start
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle",\n"popBack", "popFront"]\n[[], [1], [2], [3], [4], [], [], [], [], []]\n
// @lcpr case=end

 */


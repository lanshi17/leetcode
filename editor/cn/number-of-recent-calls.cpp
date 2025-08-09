/*
 * @lc app=leetcode.cn id=933 lang=cpp
 * @lcpr version=30202
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter {
public:
    RecentCounter()=default;
    
    int ping(int t) {
        q.push(t);
        while (q.front()<t-3000) {
          q.pop();
        }
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end



/*
// @lcpr case=start
// ["RecentCounter", "ping", "ping", "ping", "ping"]\n[[], [1], [100], [3001], [3002]]\n
// @lcpr case=end

 */


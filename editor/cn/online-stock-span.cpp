/*
 * @lc app=leetcode.cn id=901 lang=cpp
 * @lcpr version=30202
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner()=default;
    
    int next(int price) {
        int count=1;
        while (!s.empty()&&price>=s.top().first) {
          pair<int,int> prev=s.top();
          s.pop();
          count+=prev.second;
        }
        s.push({price,count});
        return count;
    }
private:
    stack<pair<int,int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end



/*
// @lcpr case=start
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]\n[[], [100], [80], [60], [70], [60], [75], [85]]\n
// @lcpr case=end

 */


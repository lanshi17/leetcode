/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30202
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       auto nums=move(temperatures);
       int n=nums.size();
       vector<int> res(n);
       stack<int> s;
       for (int i = n - 1; i >= 0; i--)
       {
        while (!s.empty()&&nums[s.top()]<=nums[i]) {
          s.pop();
        }
        res[i]=s.empty()?0:s.top()-i;
        s.push(i);
       }
       return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */


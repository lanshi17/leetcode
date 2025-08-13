/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 * @lcpr version=30202
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       int n=heights.size();
       vector<int> res(n);
       stack<int> s;
       for (int i = n - 1; i >= 0; i--)
       {
        int count=0;
        while (!s.empty()&&s.top()<heights[i]) {
          s.pop();
          count++;
        }
        res[i]=s.empty()?count:count+1;
        s.push(heights[i]);
       } 
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,6,8,5,11,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,3,10]\n
// @lcpr case=end

 */


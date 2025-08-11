/*
 * @lc app=leetcode.cn id=503 lang=cpp
 * @lcpr version=30202
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n=nums.size();
       stack<int> s;
       vector<int> res(n);
       for (int i = 2*n - 1; i >= 0; i--)
       {
        while (!s.empty()&&s.top()<=nums[i%n]) {
          s.pop();
        }
        res[i%n]=s.empty()?-1:s.top();
        s.push(nums[i%n]);
       } 
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,3]\n
// @lcpr case=end

 */


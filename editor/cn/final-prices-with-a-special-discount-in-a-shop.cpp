/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 * @lcpr version=30202
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       int n=prices.size();
       vector<int> res(n);
       auto nextElement=nextLessOrEqualElement(prices);
       for (int i = 0; i < n; ++i) {
         if (nextElement[i]!=-1) {
           res[i]=prices[i]-nextElement[i];
         }else
         {
            res[i]=prices[i];
         }
       }
       return res;
    }
    vector<int> nextLessOrEqualElement(vector<int> &nums){
        int n=nums.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty()&&s.top()>nums[i]) {
              s.pop();
            }
            res[i]=s.empty()?-1:s.top();
            s.push(nums[i]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,4,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [10,1,1,6]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30201
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int p=nums.size()-1;
        vector<int> res(nums.size());
        while (i<=j) {
          if (abs(nums[i])>abs(nums[j])) {
            res[p]=pow(nums[i],2);
            i++;
          }else
          {
            res[p]=pow(nums[j],2);
            j--;
          }
          p--;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */


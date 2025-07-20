/*
 * @lc app=leetcode.cn id=LCR 179 lang=cpp
 * @lcpr version=30200
 *
 * [LCR 179] 查找总价格为目标值的两个商品
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        vector<int> res;
        if (price.empty()) {
          return res;
        }
        
        int left=0,right=price.size()-1;
        while (left<right) {
          int sum=price[left]+price[right];
          if (sum<target) {
            left++;
          }else if (sum>target)
          {
            right--;
          }else{
            res.push_back(price[left]);
            res.push_back(price[right]);
            return res;
          }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3, 9, 12, 15]\n18\n
// @lcpr case=end

// @lcpr case=start
// [8, 21, 27, 34, 52, 66]\n61\n
// @lcpr case=end

 */


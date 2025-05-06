/*
 * @lc app=leetcode.cn id=LCR 006 lang=cpp
 * @lcpr version=30200
 *
 * [LCR 006] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left=0,right=numbers.size()-1;
        while (left<right) {
          int sum=numbers[left]+numbers[right];
          if (sum<target) {
            left++;
          }else if (sum>target)
          {
            right--; 
          }else{
            res.push_back(left);
            res.push_back(right);
            break;
          }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,6,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */


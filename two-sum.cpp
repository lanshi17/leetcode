/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30201
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> valToIndex;
       for (int i = 0; i < nums.size(); ++i) {
         int need=target-nums[i];
         if (valToIndex.find(need)!=valToIndex.end()) {
           return {valToIndex[need],i};
         }
         valToIndex[nums[i]]=i;
       }
       return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */


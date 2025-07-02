/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30201
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> res;
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int target=0;
       for (int i = 0; i < n; ++i) {
         vector<vector<int>> tuples=twoSumTarget(nums,i+1,target-nums[i]);
         for (auto& tuple : tuples) {
           tuple.push_back(nums[i]);
           res.push_back(tuple);
         }
         while (i<n-1&&nums[i]==nums[i+1]) {
           i++;
         }
       }
       return res; 
    }
private:
    vector<vector<int>> twoSumTarget(vector<int> nums,int start,int target){
       int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;

            } else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            } else {
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */


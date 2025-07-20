/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30201
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return nSumTarget(nums,4,0,target);
    }
private:
    vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, long target){
        int sz=nums.size();
        vector<vector<int>> res;
        if (n<2||sz<n) {
          return res;
        }
        if (n==2) {
            int lo = start, hi = sz - 1;
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
        }else
        {
            for (int i = start; i < sz; ++i) {
              vector<vector<int>> sub=nSumTarget(nums,n-1,i+1,target-nums[i]);
              for(auto &arr : sub)
              {
                arr.push_back(nums[i]);
                res.push_back(arr);
              }
              while (i<sz-1&&nums[i]==nums[i+1]) {
                i++;
              }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */


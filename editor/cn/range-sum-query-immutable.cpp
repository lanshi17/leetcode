/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=30201
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size()+1);
        for (int i = 1; i < preSum.size(); ++i) {
          preSum[i]=preSum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1]-preSum[left];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumArray", "sumRange", "sumRange", "sumRange"]\n[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]\n
// @lcpr case=end

 */


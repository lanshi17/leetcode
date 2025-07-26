/*
 * @lc app=leetcode.cn id=528 lang=cpp
 * @lcpr version=30202
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& w) {
        int n=w.size();
        preSum.resize(n+1);
        preSum[0]=0;
        for (int i = 1; i <= n; ++i) {
          preSum[i]=preSum[i-1]+w[i-1];
        }
        dis=uniform_int_distribution<>(1,preSum[n]);
    }
    
    int pickIndex() {
        int n=preSum.size();
        int target=dis(gen);
        return left_bound(preSum,target)-1;
    }
    int  left_bound(vector<int> &nums,int target){
        int left=0,right=nums.size()-1;
        while (left<=right) {
          int mid=left+(right-left)/2;
          if (nums[mid]<target) {
            left=mid+1;
          }else
          {
            right=mid-1;
          }
        }
        return left;
    }
private:
    vector<int> preSum;
    mt19937 gen;
    uniform_int_distribution<> dis;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Solution","pickIndex"]\n[[[1]],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]\n[[[1,3]],[],[],[],[],[]]\n
// @lcpr case=end

 */


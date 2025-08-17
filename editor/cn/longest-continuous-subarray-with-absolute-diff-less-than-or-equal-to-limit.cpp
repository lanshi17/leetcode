/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 * @lcpr version=30202
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       deque<int> maxDq;
       deque<int> minDq;
       int left=0,res=0;
       for (int right = 0; right < nums.size(); ++right) {
         while (!maxDq.empty()&&nums[maxDq.back()]<=nums[right]) {
           maxDq.pop_back();
         }
         maxDq.push_back(right);
         while (!minDq.empty()&&nums[minDq.back()]>=nums[right]) {
           minDq.pop_back();
         }
         minDq.push_back(right);
         while ((nums[maxDq.front()]-nums[minDq.front()])>limit) {
           if (maxDq.front()==left) {
             maxDq.pop_front();
           }
           if (minDq.front()==left) {
             minDq.pop_front();
           }
           left++;
         }
         res=max(res,right-left+1);
       } 
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,2,4,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [10,1,2,4,7,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,2,4,4,2,2]\n0\n
// @lcpr case=end

 */


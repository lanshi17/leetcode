/*
 * @lc app=leetcode.cn id=LCR 172 lang=cpp
 * @lcpr version=30201
 *
 * [LCR 172] 统计目标成绩的出现次数
 */

// @lc code=start
class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
       return right_bound(scores,target)-left_bound(scores,target)+1; 
    }
    int left_bound(vector<int> &nums,int target){
        int left=0,right=nums.size()-1;
        while (left<=right) {
          int mid=left+(right-left)/2;
          if (nums[mid]<target) {
            left=mid+1;
          }else if (nums[mid]>target)
          {
            right=mid-1;
          }else{
            right=mid-1;
          }
        }
        return left;
    }
     int right_bound(vector<int> &nums,int target){
        int left=0,right=nums.size()-1;
        while (left<=right) {
          int mid=left+(right-left)/2;
          if (nums[mid]>target) {
            right=mid-1;
          }else if (nums[mid]<target)
          {
            left=mid+1;
          }else{
            left=mid+1;
          }
        }
        return right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2, 2, 3, 4, 4, 4, 5, 6, 6, 8]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3, 5, 7, 9]\n6\n
// @lcpr case=end

 */


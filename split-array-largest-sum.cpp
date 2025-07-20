/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=30201
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
       int left=0,right=nums.size()-1;
       for(auto num : nums)
       {
        left=max(left,num);
        right+=num;
       } 
       while (left<=right) {
         int mid=left+(right-left)/2;
         if (f(nums,mid)>k) {
           left=mid+1;
         }else
         {
            right=mid-1;
         }
       }
       return left;
    }
    int f(vector<int> &nums,int target){
        int res=0;
        for (int i = 0; i < nums.size(); ) {
          int sum=target;
          while (i<nums.size()) {
            if (sum<nums[i]) {
              break;
            }else
            {
                sum-=nums[i];
            }
            i++;
          }
          res++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */


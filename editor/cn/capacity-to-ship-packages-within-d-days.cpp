/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 * @lcpr version=30201
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int left=0,right=weights.size()-1;
       for(auto weight: weights)
       {
            left=max(left,weight);
            right+=weight;
       }
       while (left<=right) {
         int mid=left+(right-left)/2;
         if (f(weights,mid)>days) {
           left=mid+1;
         }else
         {
            right=mid-1;
         }
       }
       return left;
    }
    int f(vector<int> &nums,int target){
        int days=0;
        for (int i = 0; i < nums.size(); ) {
          int cap=target;
          while (i<nums.size()) {
            if (cap<nums[i]) {
              break;
            }else
            {
                cap-=nums[i];
            }
            i++;
          }
          days++;
        }
        return days;
    }
   
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,1]\n4\n
// @lcpr case=end

 */


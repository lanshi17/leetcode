/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30201
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int p0=0,p2=nums.size()-1,p=0;
       while (p<=p2) {
         if (nums[p]==0) {
           swap(nums,p0,p);
           p0++;
         }else if (nums[p]==2)
         {
            swap(nums,p2,p);  
            p2--;
         }else if (nums[p]==1)
         {
           p++;  
         }
         if (p<p0) {
           p=p0;
         }
       } 
    }
    void swap(vector<int> &nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=88 lang=cpp
 * @lcpr version=30201
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1,j=n-1;
       int p=nums1.size()-1;
       while (i>=0&&j>=0) {
         if (nums1[i]>nums2[j]) {
           nums1[p]=nums1[i];
           i--;
         }else
         {
            nums1[p]=nums2[j];
            j--;
         }
         p--;
       } 
       while (j>=0) {
         nums1[p]=nums2[j];
         j--;
         p--;
       }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */


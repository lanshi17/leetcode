/*
 * @lc app=leetcode.cn id=658 lang=cpp
 * @lcpr version=30201
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int p = left_bound(arr, x);
        vector<int> res;
        int left = p - 1, right = p;
        while (right - left - 1 < k) {
            if (left == -1) {
                right++;
            } else if (right == arr.size()) {
                left--;
            } else if (x - arr[left] > arr[right] - x) {
                right++;
            } else {
                left--;
            }
        }
        for (int i = left + 1; i < right; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
    int left_bound(vector<int>& nums,int target){
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
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,4,5]\n4\n-1\n
// @lcpr case=end

 */


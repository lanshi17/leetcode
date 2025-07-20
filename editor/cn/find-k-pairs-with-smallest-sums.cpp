/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30104
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       auto cmp=[](vector<int> &a,vector<int> &b){return a[0]+a[1]>b[0]+b[1];};
       priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
       for (int i = 0; i < nums1.size(); ++i) {
         pq.push({nums1[i],nums2[0],0});
       }
       vector<vector<int>> res;
       while (!pq.empty()&&k>0) {
         vector<int> cur=pq.top();
         pq.pop();
         k--;
         int next_index=cur[2]+1;
         if (next_index<nums2.size()) {
           pq.push({cur[0],nums2[next_index],next_index});
         }
         res.push_back({cur[0],cur[1]});
       }
       return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */


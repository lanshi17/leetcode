/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=30202
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> nextGreaterMap;
       stack<int> s;
       vector<int> res;
       for (int i = nums2.size() - 1; i >= 0; i--)
       {
        while (!s.empty()&&s.top()<=nums2[i]) {
          s.pop();
        }
        nextGreaterMap[nums2[i]]=s.empty()?-1:s.top();
        s.push(nums2[i]);
       }
       for(auto num : nums1)
       {
        res.push_back(nextGreaterMap[num]);
       }
       return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */


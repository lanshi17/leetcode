/*
 * @lc app=leetcode.cn id=525 lang=cpp
 * @lcpr version=30201
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int> countIndexMap;
       countIndexMap[0]=-1;
       int maxLength=0;
       int count=0;
       for (int i = 0; i < nums.size(); i++)
       {
            if (nums[i]==1) {
              count++;
            }else
            {
                count--;
            }
            if (countIndexMap.find(count)!=countIndexMap.end()) {
              maxLength=max(maxLength,i-countIndexMap[count]);
            }else{
                countIndexMap[count]=i;
            }
       } 
       return maxLength;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,1,1,0,0,0]\n
// @lcpr case=end

 */


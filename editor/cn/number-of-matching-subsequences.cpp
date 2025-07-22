/*
 * @lc app=leetcode.cn id=792 lang=cpp
 * @lcpr version=30201
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       vector<vector<int>> charToIndex(26);
       for (int i = 0; i < s.length(); ++i) {
         char c=s[i];
         charToIndex[c-'a'].push_back(i);
       }
       int res=0;
       for(const auto& word : words)
       {
        int i=0,j=0;//i为word指针，j为s的指针。
        while (i<word.length()) {
          char c=word[i];
          if (charToIndex[c-'a'].empty()) {
            break;
          }
          int pos=left_bound(charToIndex[c-'a'],j);
          if (pos==charToIndex[c-'a'].size()) {
            break;
          }
          j=charToIndex[c-'a'][pos];
          j++;
          i++;
        }
        if (i==word.length()) {
          res++;
        }
       }
       return res;
    }
    int left_bound(vector<int>&nums,int target){
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
// "abcde"\n["a","bb","acd","ace"]\n
// @lcpr case=end

// @lcpr case=start
// "dsahjpjauf"\n["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]\n
// @lcpr case=end

 */


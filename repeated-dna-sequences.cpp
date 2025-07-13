/*
 * @lc app=leetcode.cn id=187 lang=cpp
 * @lcpr version=30201
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       vector<int> nums(s.size());
       for (int i = 0; i < s.size(); ++i) {
         switch (s[i])
         {
            case 'A':
                nums[i]=0;
                break;
            case 'C':
                nums[i]=1;
                break;
            case 'G':
                nums[i]=2;
                break;
            case 'T':
                nums[i]=3;
                break;
            default:
                break;
         }
       } 
       unordered_set<int> seen;
       unordered_set<string> res;
       int L=10;
       int R=4;//四进制
       int RL=pow(R,L-1);
       int windowHash=0;
       int left=0,right=0;
       while (right<nums.size()) {
         windowHash=R*windowHash+nums[right++];
         if (right-left==L) {
           if (seen.count(windowHash)) {
             res.insert(s.substr(left,L));
           }else
           {
            seen.insert(windowHash);
           }
           windowHash=windowHash-RL*nums[left++];
         }
       }
       return vector<string>(res.begin(),res.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"\n
// @lcpr case=end

// @lcpr case=start
// "AAAAAAAAAAAAA"\n
// @lcpr case=end

 */


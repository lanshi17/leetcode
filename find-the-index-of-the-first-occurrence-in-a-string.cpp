/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30201
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int L=needle.size();
        int R=256;
        int Q=1e9+7;
        long RL=1;
        for (int i = 0; i <=L-1; ++i) {
          RL=(RL*R)%Q;
        }
        long needleHash=0;
        for (int i = 0; i < needle.size(); ++i) {
          needleHash=(needleHash*R+needle.at(i))%Q;
        }
        long windowHash=0;
        int left=0,right=0;
        while (right<haystack.size()) {
          windowHash=((R*windowHash)%Q+haystack.at(right++))%Q;
          if (right-left==L) {
            if (needle.compare(haystack.substr(left,L))==0) {
              return left;
            }
            windowHash=((windowHash-(haystack.at(left++)*RL)%Q+Q))%Q;
          }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */


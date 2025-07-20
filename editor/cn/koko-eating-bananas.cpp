/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30201
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int left=1,right=1e9+7;
       while (left<=right) {
         int mid=left+(right-left)/2;
         if (f(piles,mid)>h) {
           left=mid+1;
         }else
         {
            right=mid-1;
         }
       } 
       return left;
    }
    long f(vector<int> &piles,int x){
        long hours=0;
        for (int i = 0; i < piles.size(); ++i) {
          hours+=piles[i]/x;
          if (piles[i]%x>0) {
            hours++;
          }
        }
        return hours;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */


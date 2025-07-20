/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 * @lcpr version=30201
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n,0);
        for (const auto& booking : bookings) {
          int first=booking[0]-1;
          int last=booking[1];
          int seats=booking[2];
          answer[first]+=seats;
          if (last<n) {
            answer[last]-=seats;
          }
        }
        for (int i = 1; i < n; ++i) {
          answer[i]+=answer[i-1];
        }
        return answer;
    }
 
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,10],[2,3,20],[2,5,25]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,10],[2,2,15]]\n2\n
// @lcpr case=end

 */


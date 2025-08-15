/*
 * @lc app=leetcode.cn id=853 lang=cpp
 * @lcpr version=30202
 *
 * [853] 车队
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n=position.size(),res=0;
       vector<vector<int>> cars(n,vector<int>(2));
       vector<double> times(n);
       double maxTime=0;
       for (int i = 0; i < n; ++i) {
         cars[i][0]=position[i];
         cars[i][1]=speed[i];
       } 
       sort(cars.begin(),cars.end());
      for (int i = 0; i < n; ++i) {
        int pos=cars[i][0];
        int vel=cars[i][1];
        times[i]=static_cast<double>(target-pos)/vel;
      } 
      for (int i = n - 1; i >= 0; i--)
      {
        if (times[i]>maxTime) {
          maxTime=times[i];
          res++;
        }
      }
      return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n[10,8,0,5,3]\n[2,4,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[3]\n[3]\n
// @lcpr case=end

// @lcpr case=start
// 100\n[0,2,4]\n[4,2,1]\n
// @lcpr case=end

 */


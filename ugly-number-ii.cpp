/*
 * @lc app=leetcode.cn id=264 lang=cpp
 * @lcpr version=30104
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int p2=1,p3=1,p5=1;//结点指针
        int product2=1,product3=1,product5=1;//结点存储的值
        vector<int> ugly(n+1);//结果
        int p=1;//结果的指针
        while (p<=n) {
          int min=std::min({product2,product3,product5});
          ugly[p]=min;
          p++;
          if (product2==min) {
            product2=2*ugly[p2];
            p2++;
          }
          if (product3==min) {
            product3=3*ugly[p3];
            p3++;
          }
          if (product5==min) {
            product5=5*ugly[p5];
            p5++;
          }
        }
        return ugly[n];

    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


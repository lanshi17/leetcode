/*
 * @lc app=leetcode.cn id=1352 lang=cpp
 * @lcpr version=30201
 *
 * [1352] 最后 K 个数的乘积
 */

// @lc code=start
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        preProduct.push_back(1);
    }
    
    void add(int num) {
        if (num==0) {
          preProduct.clear();
          preProduct.push_back(1);
          return;
        }
        int n=preProduct.size();
        preProduct.push_back(preProduct[n-1]*num);
    }
    
    int getProduct(int k) {
        int n=preProduct.size();
        if (k>n-1) {
          return 0;
        }
        return preProduct[n-1]/preProduct[n-k-1];
    }

private:
    vector<int> preProduct;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end



/*
// @lcpr case=start
// ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]\n[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]\n
// @lcpr case=end

 */


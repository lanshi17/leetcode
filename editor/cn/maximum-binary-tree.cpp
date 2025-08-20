/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30202
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return build(nums,0,nums.size()-1); 
    }
    TreeNode* build(vector<int>&nums,int lo,int hi){
        if (lo>hi) {
          return nullptr;
        }
        int index=-1,maxval=INT_MIN;
        for (int i = lo; i <=hi; ++i) {
          if (maxval<nums[i]) {
            index=i;
            maxval=nums[i];
          }
        }
        TreeNode* root=new TreeNode(maxval);
        root->left=build(nums,lo,index-1);
        root->right=build(nums,index+1,hi);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30201
 *
 * [543] 二叉树的直径
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
    int maxD=0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxD;
    }
private:
    int maxDepth(TreeNode *root){
        if (root==nullptr) {
          return 0;
        }
        int leftMax=maxDepth(root->left);
        int rightMax=maxDepth(root->right);
        maxD=std::max(maxD,rightMax+leftMax);
        return 1+std::max(rightMax,leftMax);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */


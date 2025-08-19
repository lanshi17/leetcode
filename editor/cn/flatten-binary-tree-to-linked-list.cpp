/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30202
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
       if (root==nullptr) {
         return;
       } 
       flatten(root->left);
       flatten(root->right);
       TreeNode* left=root->left;
       TreeNode* right=root->right;
       root->left=nullptr;
       root->right=left;
       TreeNode* p=root;
       while (p->right!=nullptr) {
         p=p->right;
       }
       p->right=right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


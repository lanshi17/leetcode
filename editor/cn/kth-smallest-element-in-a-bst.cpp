/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30202
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int kthSmallest(TreeNode* root, int k) {
       traverse(root,k);
       return res; 
    }
private:
    int res=0,rank=0;
    void traverse(TreeNode* root,int k){
        if (root==nullptr) {
          return;
        }
        traverse(root->left,k);
        rank++;
        if (k==rank) {
          res=root->val;
          return;
        }
        traverse(root->right,k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */


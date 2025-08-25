/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30202
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
       if (root==nullptr) {
         return nullptr;
       } 
       if (root->val==key) {
         if (root->left==nullptr) {
           return root->right;
         }
         if (root->right==nullptr) {
           return root->left;
         }
         TreeNode* minNode=getMin(root->right);
         root->right=deleteNode(root->right,minNode->val);
         minNode->left=root->left;
         minNode->right=root->right;
         root=minNode;
    }else if (root->val>key)
    {
        root->left=deleteNode(root->left,key);
    }else if (root->val<key)
    {
        root->right=deleteNode(root->right,key);   
    }
    return root;

    }
private:
    TreeNode* getMin(TreeNode* root){
        while (root->left!=nullptr) {
          root=root->left;
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */


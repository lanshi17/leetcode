/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30202
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
          valToIndex[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1,
                    inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& postorder,int postStart,int postEnd,
        vector<int>& inorder,int inStart,int inEnd){
            if (inStart>inEnd) {
              return nullptr;
            }
            int rootVal=postorder[postEnd];
            int index=valToIndex[rootVal];
            int leftSize=index-inStart;
            TreeNode* root=new TreeNode(rootVal);
            root->left=build(postorder,postStart,postStart+leftSize-1,
            inorder,inStart,index-1);
            root->right=build(postorder,postStart+leftSize,postEnd-1,
            inorder,index+1,inEnd);

            return root;
        }
private:
    unordered_map<int,int> valToIndex; 
    
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */


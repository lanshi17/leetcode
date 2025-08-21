/*
 * @lc app=leetcode.cn id=889 lang=cpp
 * @lcpr version=30202
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); ++i) {
          valToIndex[postorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,
                    postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,
        vector<int>& postorder,int postStart,int postEnd){
            if (preStart>preEnd) {
              return nullptr;
            }
            if (preStart==preEnd) {
              return new TreeNode(preorder[preStart]);
            }

            int rootVal=preorder[preStart];
            int leftRootVal=preorder[preStart+1];
            int index=valToIndex[leftRootVal];
            int leftSize=index-postStart+1;
            TreeNode* root=new TreeNode(rootVal);
            root->left=build(preorder,preStart+1,preStart+leftSize,
            postorder,postStart,index);
            root->right=build(preorder,preStart+leftSize+1,preEnd,
            postorder,index+1,postEnd-1);
            return root;
    }
private:
    unordered_map<int,int> valToIndex; 
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */


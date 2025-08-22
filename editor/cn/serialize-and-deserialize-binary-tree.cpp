/*
 * @lc app=leetcode.cn id=297 lang=cpp
 * @lcpr version=30202
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if (!root) {
         return "#";
       } 
       string res=to_string(root->val);
       res+=","+serialize(root->left);
       res+=","+serialize(root->right);
       return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string item;
        while (getline(ss,item,',')) {
          nodes.push(item);
        }
        return deserializeHelper(nodes);
    }
private:
    TreeNode* deserializeHelper(queue<string>& nodes){
        if (nodes.empty()) {
          return nullptr;
        }
        string val=nodes.front();
        nodes.pop();
        if (val=="#") {
          return nullptr;
        }
        TreeNode* root=new TreeNode(stoi(val));
        root->left=deserializeHelper(nodes);
        root->right=deserializeHelper(nodes);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,null,4,5]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */


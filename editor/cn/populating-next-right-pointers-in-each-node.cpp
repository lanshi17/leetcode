/*
 * @lc app=leetcode.cn id=116 lang=cpp
 * @lcpr version=30202
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if (root==nullptr) {
         return nullptr;
       } 
       traverse(root->left,root->right);
       return root;
    }
    auto traverse(Node* node1,Node* node2)->void{
        if (node1==nullptr||node2==nullptr) {
          return;
        }
        node1->next=node2;
        traverse(node1->left,node1->right);
        traverse(node2->left,node2->right);
        traverse(node1->right,node2->left);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


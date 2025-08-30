/*
 * @lc app=leetcode.cn id=1022 lang=rust
 * @lcpr version=30202
 *
 * [1022] 从根到叶的二进制数之和
 */

// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
       Self::dfs(&root,0) 
    }
    fn dfs(node:&Option<Rc<RefCell<TreeNode>>>,curSum:i32)->i32{
        if let Some(n)=node{
            let node_ref=n.borrow();
            let new_sum=(curSum<<1)|node_ref.val;
            if node_ref.left.is_none()&&node_ref.right.is_none(){
                return new_sum;
            }
            Self::dfs(&node_ref.left,new_sum)+Self::dfs(&node_ref.right,new_sum)
        }else{
            0
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */


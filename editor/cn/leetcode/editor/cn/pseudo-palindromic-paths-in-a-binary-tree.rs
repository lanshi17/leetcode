/*
 * @lc app=leetcode.cn id=1457 lang=rust
 * @lcpr version=30202
 *
 * [1457] 二叉树中的伪回文路径
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
    pub fn pseudo_palindromic_paths (root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
       Self::dfs(&root,0)
    }
    fn dfs(node:&Option<Rc<RefCell<TreeNode>>>,curSum:i32)->i32{
        if let Some(n)=node{
            let node_ref=n.borrow();
            let new_sum=curSum^(1<<node_ref.val);
            if node_ref.left.is_none()&&node_ref.right.is_none(){
                if new_sum==0||(new_sum&(new_sum-1))==0{
                    return 1;
                }
                return 0;
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
// [2,3,1,3,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,1,3,null,null,null,null,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=700 lang=rust
 * @lcpr version=30202
 *
 * [700] 二叉搜索树中的搜索
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
    pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
       match root{
        Some(node)=>{
            let node_ref=node.borrow();
            if node_ref.val==val{
                drop(node_ref);
                Some(node)
            }else if node_ref.val>val{
                drop(node_ref);
                Self::search_bst(node.borrow().left.clone(),val)
            }else{
                drop(node_ref);
                Self::search_bst(node.borrow().right.clone(),val)
            }
        }
        None=>None,
       }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */


/*
 * @lc app=leetcode.cn id=129 lang=rust
 * @lcpr version=30202
 *
 * [129] 求根节点到叶节点数字之和
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
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = 0;
        if let Some(node) = root {
            Self::traverse(node, 0, &mut res);
        }
        res
    }
    fn traverse(node: Rc<RefCell<TreeNode>>, current_num: i32, res: &mut i32) {
        let node_ref = node.borrow();
        let val = node_ref.val;
        let new_num = current_num * 10 + val;
        
        if node_ref.left.is_none() && node_ref.right.is_none() {
            *res += new_num;
            return;
        }
        
        if let Some(left_child) = &node_ref.left {
            Self::traverse(left_child.clone(), new_num, res);
        }
        if let Some(right_child) = &node_ref.right {
            Self::traverse(right_child.clone(), new_num, res);
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,0,5,1]\n
// @lcpr case=end

 */


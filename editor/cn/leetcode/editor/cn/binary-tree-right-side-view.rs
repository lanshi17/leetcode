/*
 * @lc app=leetcode.cn id=199 lang=rust
 * @lcpr version=30202
 *
 * [199] 二叉树的右视图
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
use std::collections::VecDeque;
impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res=Vec::new();
        if let Some(root_node)=root{
            let mut q=VecDeque::new();
            q.push_back(root_node);
            while !q.is_empty(){
                let sz=q.len();
                for i in 0..sz{
                    let node=q.pop_front().unwrap();
                    let node_ref=node.borrow();
                    if i==sz-1{
                        res.push(node_ref.val);
                    }
                    if let Some(ref left)=node_ref.left{
                        q.push_back(left.clone());
                    }
                    if let Some(ref right)=node_ref.right{
                        q.push_back(right.clone());
                    }
                    
                }
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */


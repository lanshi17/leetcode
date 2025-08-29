/*
 * @lc app=leetcode.cn id=988 lang=rust
 * @lcpr version=30202
 *
 * [988] 从叶结点开始的最小字符串
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
    pub fn smallest_from_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> String {
       Self::dfs(&root,"".to_string()) 
    }
    fn dfs(node:&Option<Rc<RefCell<TreeNode>>>,suffix:String)->String{
        if let Some(n)=node{
            let node_ref=n.borrow();
            let ch=(b'a'+node_ref.val as u8)as char;
            let new_suffix=format!("{}{}",ch,suffix);
            if node_ref.left.is_none()&&node_ref.right.is_none(){
                return new_suffix;
            }
            let left_res=if node_ref.left.is_some(){
                Self::dfs(&node_ref.left,new_suffix.clone())
            }else{
                String::from("~")
            };
            let right_res=if node_ref.right.is_some(){
                Self::dfs(&node_ref.right,new_suffix.clone())
            }else{
                String::from("~")
            };
            if left_res<right_res{
                left_res
            }else{
                right_res
            }
        }else{
            String::from("~")
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,4,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [25,1,3,1,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,null,1,0,null,0]\n
// @lcpr case=end

 */


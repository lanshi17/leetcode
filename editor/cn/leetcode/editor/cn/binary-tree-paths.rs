/*
 * @lc app=leetcode.cn id=257 lang=rust
 * @lcpr version=30202
 *
 * [257] 二叉树的所有路径
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
    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
       let mut res=Vec::new();
       if let Some(node)=root{
        Self::dfs(node,String::new(),&mut res);
       }
       res
    }
    fn dfs(node:Rc<RefCell<TreeNode>>,path:String,res:&mut Vec<String>){
        let node_ref=node.borrow();
        let val=node_ref.val;
        let curPath=if path.is_empty(){
            format!("{}",val)
        }else{
            format!("{}->{}",path,val)
        };
        if node_ref.left.is_none()&& node_ref.right.is_none(){
            res.push(curPath);
            return;
        }
        if let Some(left_child)=&node_ref.left{
            Self::dfs(left_child.clone(),curPath.clone(),res);
        }
        if let Some(right_child)=&node_ref.right{
            Self::dfs(right_child.clone(),curPath.clone(),res);
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */


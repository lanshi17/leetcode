/*
 * @lc app=leetcode.cn id=95 lang=rust
 * @lcpr version=30202
 *
 * [95] 不同的二叉搜索树 II
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
use std::collections::HashMap;
impl Solution {
    pub fn generate_trees(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
       if n==0{
        return vec![];
       } 
       let mut memo = HashMap::new();
       Self::build(1,n,&mut memo)
    }
    fn build(lo:i32,hi:i32,memo:&mut HashMap<(i32,i32),Vec<Option<Rc<RefCell<TreeNode>>>>>)->Vec<Option<Rc<RefCell<TreeNode>>>>{
        if let Some(result) = memo.get(&(lo, hi)) {
            return result.clone();
        }
        
        let mut res=Vec::new();
        if lo>hi{
            res.push(None);
            memo.insert((lo, hi), res.clone());
            return res;
        }
        
        for i in lo..=hi{
            let left_tree=Self::build(lo,i-1,memo);
            let right_tree=Self::build(i+1,hi,memo);
            for left in &left_tree{
                for right in &right_tree{
                    let root=Rc::new(RefCell::new(TreeNode::new(i)));
                    root.borrow_mut().left=left.clone();
                    root.borrow_mut().right=right.clone();
                    res.push(Some(root));
                }
            }
        }
        memo.insert((lo, hi), res.clone());
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */


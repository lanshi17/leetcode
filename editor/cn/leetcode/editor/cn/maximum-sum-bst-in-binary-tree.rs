/*
 * @lc app=leetcode.cn id=1373 lang=rust
 * @lcpr version=30202
 *
 * [1373] 二叉搜索子树的最大键值和
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
struct BstInfo{
    is_bst:bool,
    min_val:i32,
    max_val:i32,
    sum:i32,
}
impl Solution {
    pub fn max_sum_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_sum=0;
        Self::findMaxMinSum(root,&mut max_sum);
        max_sum
    }
    fn findMaxMinSum(root:Option<Rc<RefCell<TreeNode>>>,max_sum:&mut i32)->BstInfo{
        if root.is_none(){
            return BstInfo{is_bst:true,min_val:i32::MAX,max_val:i32::MIN,sum:0};
        }
        let node=root.unwrap();
        let node_ref=node.borrow();
        let left=Self::findMaxMinSum(node_ref.left.clone(),max_sum);
        let right=Self::findMaxMinSum(node_ref.right.clone(),max_sum);
        if left.is_bst && right.is_bst && node_ref.val>left.max_val && node_ref.val<right.min_val{
            let cur_sum=left.sum+right.sum+node_ref.val;
            *max_sum=(*max_sum).max(cur_sum);
            BstInfo{
                is_bst:true,
                min_val:left.min_val.min(node_ref.val),
                max_val:right.max_val.max(node_ref.val),
                sum:cur_sum,
            }
        }else{
            *max_sum=(*max_sum).max(left.sum).max(right.sum);
            BstInfo{
                is_bst:false,
                min_val:i32::MIN,
                max_val:i32::MAX,
                sum:0
            }
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,null,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-2,-5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,3,null,6,3]\n
// @lcpr case=end

 */


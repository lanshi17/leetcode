/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30201
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode *a,*b;
        a=b=head;
        for(int i=0;i<k;i++){
            if(b==nullptr) return head;
            b=b->next;
        }
        ListNode *newHead=reverseN(a,k);
        a->next=reverseKGroup(b,k);
        return newHead;
    }
    ListNode*reverseN(ListNode*head,int n){
        if (head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode *pre,*cur,*nxt;
        pre=nullptr;cur=head;nxt=head->next;
        while (n>0)
        {
            cur->next=pre;
            pre=cur;
            cur=nxt;
            if (nxt!=nullptr)
            {
                nxt=nxt->next;
            }
            n--;
        }
        head->next=cur;
        return pre;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */


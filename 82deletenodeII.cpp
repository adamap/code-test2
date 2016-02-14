//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
//
//For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
//  Given 1->1->1->2->3, return 2->3. 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if ( NULL == head)
        {
            return head;
        }
        ListNode*dummynode = new ListNode(-1000);
        
        dummynode->next = head;
        
        ListNode*prev = dummynode;
        ListNode*cur = head;
        ListNode*next= head->next;
        
        while(cur)
        {
            while(next && next->val == cur->val)
            {
                ListNode*tempnode = cur;
                cur = cur->next;
                next = next->next;
                delete tempnode;
            }
            
            if ( prev->next == cur)
            {
                prev = cur;
                cur = next;
                if (next)
                {
                    next = next->next;
                }
            }
            else
            {
                prev->next = next;
                cur = next;
                if (next)
                {
                    next = next->next;
                }
            }
        }
        
        ListNode *ret = dummynode->next;
        delete dummynode;
        return ret;
        
    }
};

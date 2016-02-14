//Given a sorted linked list, delete all duplicates such that each element appear only once. 
//
//For example,
// Given 1->1->2, return 1->2.
//  Given 1->1->2->3->3, return 1->2->3. 

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
            while(cur && cur->val == prev->val)
            {
                ListNode*tempnode = cur;
                cur = cur->next;
                if (next)
                {
                    next = next->next;
                }
                delete tempnode;
            }
            
            prev->next = cur;
            prev = cur;
            if ( cur)
            {
                cur = cur->next;
            }
            if ( next)
            {
                next = next->next;
            }
        }
        ListNode*ret = dummynode->next;
        delete dummynode;
        return ret;
        
    }
};



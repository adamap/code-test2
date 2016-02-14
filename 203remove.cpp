//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5 
//
//Credits:

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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if ( NULL == head)
        {
            return head;
        }
        
        ListNode*dummynode = new ListNode(0);
        dummynode->next = head;
        
        ListNode*prev = dummynode;
        ListNode*cur  = head;
        ListNode*next = head->next;
        
        while(cur)
        {
            if ( cur->val == val)
            {
                prev->next = next;
                delete cur;
            }
            else
            {
                prev = cur;
            }

            cur = next;
            if ( next )
            {
                next = next->next;
            }
        }
        
        ListNode*ret = dummynode->next;
        delete dummynode;
        return ret;
    }
};

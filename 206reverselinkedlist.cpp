//Reverse a singly linked list.
//
//

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
    ListNode* reverseList(ListNode* head) 
    {
        if (NULL == head)
        {
            return head;
        }
        ListNode*dummynode = NULL;

        ListNode*prev = dummynode;
        ListNode*cur = head;
        ListNode*next = head->next;
        
        while(cur)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            if ( next)
            {
                next = next->next;
            }
        }
       
        return prev;
    }
};

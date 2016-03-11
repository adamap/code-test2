//
//
//
//Given a linked list, return the node where the cycle begins. If there is no cycle, return null. 
//
//Note: Do not modify the linked list.
//
//Follow up:
// Can you solve it without using extra space? 
//
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
    ListNode *detectCycle(ListNode *head) 
    {
        if ( head == NULL)
        {
            return NULL;
        }
        
        ListNode *slow = head, *fast = head->next;
        
        while(fast && fast->next && fast != slow)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if ( slow != fast)
        {
            return NULL;            
        }
        //
        // 1->2->1
        // head = slow = 2 when cycle detection finishs
        // then slow->next = head, head is start of cycle
       
        while(head!= slow->next)
        {
            slow = slow->next;
            head = head->next;
        }
        
        return head;
    }
};

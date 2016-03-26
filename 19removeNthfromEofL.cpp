//
//
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//      After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
//      Note:
//       Given n will always be valid.
//        Try to do this in one pass. 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head == NULL)
        {
            return NULL;
        }
        // write your code here
        int len = 0;
        ListNode *node = head;
        
        while(node)
        {
            len++;
            node = node->next;
        }
        
        if ( n > len )
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        node = head; int index = n;
        
        while(index>1)
        {
            node = node->next;
            index--;
        }
        
        
        while(node->next)
        {
            node = node->next;
            dummy = dummy->next;
        }
        
        if ( dummy->next == head)
        {
            ListNode *releasenode = head;
            head = head->next;
            delete releasenode;
            delete dummy;
            
        }
        else
        {
            ListNode *releasenode = dummy->next;
            dummy->next = dummy->next->next;
            delete releasenode;
        }
        
        return head;
    }
};

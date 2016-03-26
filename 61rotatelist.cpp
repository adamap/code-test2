//
//
//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
// Given 1->2->3->4->5->NULL and k = 2,
//  return 4->5->1->2->3->NULL.
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
ListNode* reverse(ListNode* node)
{
    if ( node == NULL)
    {
        return NULL;
    }
    
    ListNode*prev = NULL;
    ListNode*cur = node;
    ListNode*next = cur->next;
    
    while(cur)
    {
        cur->next = prev;
        prev = cur;
        cur  = next;
        if (next)
        {
            next = next->next;
        }
    }
    
    return prev;
}
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if ( head == NULL)
        {
            return NULL;
        }
        
        int len = 0;
        ListNode* node = head;
        while(node)
        {
            len++;
            node = node->next;
        }
        
        k = k%len;
        if ( k == 0)
        {
            return head;
        }
       
        node = head;
        ListNode* prev = head;
        
        int count = 0;
        while(count < k)
        {
            node = node->next;
            count++;
        }
        
        while(node->next)
        {
            node = node->next;
            prev = prev->next;
        }
        
        ListNode* ret = prev->next;
        ListNode*tail_right = node;
        ListNode*tail_left = prev;
        
        // no need to rotate, read the question next time please
        //prev = reverse(prev->next);
        tail_right->next = head;
        tail_left->next = NULL;
        
        return ret;
    }
};

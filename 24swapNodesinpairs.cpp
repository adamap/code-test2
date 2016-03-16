//
//
//Given a linked list, swap every two adjacent nodes and return its head. 
//
//For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3. 
//
// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
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
    ListNode* swapPairs(ListNode* head) 
    {
        if ( head == NULL)
        {
            return NULL;
        }
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        
        ListNode* prev = dummynode;
        ListNode* cur = head;
        ListNode* next = head->next;
        
        while(cur)
        {
            prev->next = next;
            
            if (next)
            {
                cur->next = next->next;
                next->next = cur;
            }
            else
            {
                prev->next = cur;
                cur->next = NULL;
            }
            
            prev = cur;
            cur = cur->next;
            if(cur)
            {
                next = cur->next;
            }
        }
        ListNode* ret = dummynode->next;
        delete dummynode;
        return ret;
        
        
    }
};

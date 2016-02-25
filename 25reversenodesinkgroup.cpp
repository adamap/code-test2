//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. 
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
// Given this linked list: 1->2->3->4->5 
//
// For k = 2, you should return: 2->1->4->3->5 
//
// For k = 3, you should return: 3->2->1->4->5 
// 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverseinK_helper(ListNode*node1, ListNode*node2, int k)
{
    ListNode*count = node2;
    int i = 0;
    while(count)
    {
        i++;
        count = count->next;
    }
    
    if ( i < k )
    {
        return;
    }
  
    ListNode* prev = node1;
    ListNode* cur = node2;
    ListNode* next = node2->next;
    
    i = 1;
    while (i < k)
    {
        ListNode*temp = next->next;
        next->next = cur;
        cur = next;
        next = temp;
        i++;
    }
    ListNode*temp = prev->next;
    prev->next = cur;
    temp->next = next;

    reverseinK_helper(temp, next, k);
} 
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode*dummynode = new ListNode(0);
        dummynode->next = head;
        
        reverseinK_helper(dummynode, head, k);
        
        ListNode*ret = dummynode->next;
        delete dummynode;
        
        return ret;
        
    }
};




















 

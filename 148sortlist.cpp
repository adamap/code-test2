//Sort a linked list in O(n log n) time using constant space complexity.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode*findmiddle(ListNode* head)
{
    if ( head == NULL)
    {
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while( fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode*mergeList(ListNode*left, ListNode*right)
{
    ListNode* dummynode = new ListNode(0);
    ListNode* dummynode_ptr = dummynode;
    
    while(left && right)
    {
        if ( left->val < right->val)
        {
            dummynode->next = left;
            left = left->next;
            dummynode = dummynode->next;
        }
        else
        {
            dummynode->next = right;
            right = right->next;
            dummynode = dummynode->next;
        }
    }
    
    while(left)
    {
        dummynode->next = left;
        left = left->next;
        dummynode = dummynode->next;
    }
    
    while(right)
    {
        dummynode->next = right;
        right = right->next;
        dummynode = dummynode->next;
    }
    
    ListNode*ret = dummynode_ptr->next;
    delete dummynode_ptr;
    return ret;
}

 
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if ( head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* middle = findmiddle(head);
        
        ListNode* right = sortList(middle->next);
        middle->next = NULL;
        ListNode* left = sortList(head);
        
        ListNode* ret = mergeList(left, right);
        
        return ret;
    }
};

//
//Given a singly linked list L: L0¡L1¡¡¡Ln-1¡Ln,
// reorder it to: L0¡Ln¡L1¡Ln-1¡L2¡Ln-2¡¡ 
//
// You must do this in-place without altering the nodes' values.
//
// For example,
//  Given {1,2,3,4}, reorder it to {1,4,2,3}. 
//  




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode * reverselist(ListNode * root)
{
    if (NULL == root)
    {
        return root;
    }
    
    ListNode *prev = NULL;
    ListNode *cur = root;
    ListNode *next = root->next;
    
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

ListNode *findmiddlelist(ListNode * root)
{
    
    ListNode *fast = root;
    ListNode *slow = root;
    
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
 
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if ( NULL == head)
        {
            return ;
        }
        
        ListNode *middle = findmiddlelist(head);
        if ( middle == NULL)
        {
            return;
        }
        ListNode *second = reverselist(middle->next);
        middle->next = NULL;
        
        ListNode *dummynode = new ListNode(1);
        ListNode *temp = dummynode;
        int s = 1;
        while( head && second)
        {
            if ( s == 1)
            {
                dummynode->next = head;
                dummynode = dummynode->next;
                head = head->next;
                s = 0;
            }
            else
            {
                dummynode->next = second;
                dummynode = dummynode->next;
                second = second->next;
                s = 1;
            }
        }
        while(head)
        {
            dummynode->next = head;
            dummynode = dummynode->next;
            head = head->next;
        }
        delete temp;
        
    }
};

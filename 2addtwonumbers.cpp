//
//
//
//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reversell(ListNode* node)
{
    if (node == NULL)
    {
        return node;
    }
    
    ListNode*prev = NULL;
    ListNode*cur = node;
    ListNode*next = node->next;
    
    while( cur)
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
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        //l1 = reversell(l1);
        //l2 = reversell(l2);
        
        ListNode*dummynode = new ListNode(0);
        ListNode*dummynode_ptr = dummynode;
        int carry = 0;
        while(l1 && l2)
        {
            int temp = l1->val+l2->val+carry;
            carry = temp/10;
            temp = temp%10;
            dummynode->next = new ListNode(temp);
            dummynode = dummynode->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            int temp = l1->val+carry;
            carry = temp/10;
            temp = temp%10;
            dummynode->next = new ListNode(temp);
            dummynode = dummynode->next;
            l1 = l1->next;
        }
        
        while(l2)
        {
            int temp = l2->val+carry;
            carry = temp/10;
            temp = temp%10;
            dummynode->next = new ListNode(temp);
            dummynode = dummynode->next;
            l2 = l2->next;
        }
        
        if ( carry)
        {
            dummynode->next = new ListNode(carry);
        }
        
        ListNode*ret = dummynode_ptr->next;
        delete dummynode_ptr;

        return ret;
    }
};

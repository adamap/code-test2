//
//
//
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists: 
//A:          a1->a2
//                \
//                 c1->c2->c3
//                /               
//  B:   b1->b2->b3
//
//
//  begin to intersect at node c1.
//
//
//  Notes: 
//  If the two linked lists have no intersection at all, return null.
//  The linked lists must retain their original structure after the function returns. 
//  You may assume there are no cycles anywhere in the entire linked structure.
//  Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if ( NULL == headA || NULL == headB)
        {
            return NULL;
        }
        
        ListNode *tail = headB;
        while( tail->next)
        {
            tail = tail->next;
        }
        
        tail->next = headA;
        
        ListNode *fast = headB->next, *slow = headB;
        
        while( fast && fast->next && fast != slow)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if ( fast != slow)
        {
            tail->next = NULL;
            return NULL;
        }
        
        while( headB != slow->next)
        {
            headB = headB->next;
            slow = slow->next;
        }
        tail->next = NULL;
        return headB;
    }
};

























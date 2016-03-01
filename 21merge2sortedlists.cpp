//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
       ListNode *dummynode = new ListNode(0);
       ListNode *dummynode_ptr = dummynode;
       while(l1 && l2)
       {
            if ( l1->val < l2->val)
            {
                dummynode->next = l1;
                l1 = l1->next;
                dummynode = dummynode->next;
            }
            else
            {
                dummynode->next = l2;
                l2 = l2->next;
                dummynode = dummynode->next;
            }
       }
       
       while(l1)
       {
            dummynode->next = l1;
            l1 = l1->next;
            dummynode = dummynode->next;
       }

       while(l2)
       {
            dummynode->next = l2;
            l2 = l2->next;
            dummynode = dummynode->next;
       }
       
       ListNode *ret = dummynode_ptr->next;
       delete dummynode_ptr;
       return ret;
    }
};

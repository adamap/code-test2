//
//
//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//
//
//Example:
// Given 1->2->3->4->5->NULL,
//  return 1->3->5->2->4->NULL. 
//
//  Note:
//  The relative order inside both the even and odd groups should remain as it was in the input. 
//  The first node is considered odd, the second node even and so on ... 
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
    ListNode* oddEvenList(ListNode* head) 
    {
        vector<ListNode*>oddlist;
        vector<ListNode*>evenlist;
        
        int odd = 1;
        
        while(head)
        {
            if ( odd == 1)
            {
                oddlist.push_back(head);
                odd = 0;
            }
            else
            {
                odd =1;
                evenlist.push_back(head);
            }
            head = head->next;
        }
        
        ListNode*dummynode = new ListNode(0);
        ListNode*dummynode_ptr = dummynode;
        
        for ( int i = 0; i < oddlist.size(); i++)
        {
            dummynode->next = oddlist[i];
            dummynode = dummynode->next;
        }
        
        for ( int i = 0; i < evenlist.size(); i++)
        {
            dummynode->next = evenlist[i];
            dummynode = dummynode->next;
        }
        
        dummynode->next = NULL;
        ListNode*ret = dummynode_ptr->next;
        delete dummynode_ptr;
        return ret;
    }
};




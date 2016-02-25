//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. 
//
//You should preserve the original relative order of the nodes in each of the two partitions. 
//
//For example,
// Given 1->4->3->2->5->2 and x = 3,
//  return 1->2->2->4->3->5. 
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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode*dummynode1 = new ListNode(0);
        ListNode*dummynode2 = new ListNode(0);
        
        ListNode*head1 = dummynode1;
        ListNode*head2 = dummynode2;
        
        while(head)
        {
            if ( head->val < x)
            {
                head1->next = head;
                head1 = head1->next;
            }
            else
            {
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }
        // dont forget to close right sublist
        head2->next = NULL;
        // dont forget to close right sublist
        
        head1->next = dummynode2->next;
        delete dummynode2;
        
        ListNode*ret = dummynode1->next;
        delete dummynode1;
        return ret;
        
    }
};

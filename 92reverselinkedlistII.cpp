//Reverse a linked list from position m to n. Do it in-place and in one-pass. 
//
//For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4, 
//
// return 1->4->3->2->5->NULL. 
//
// Note:
//  Given m, n satisfy the following condition:
//   1 <= m <= n <= length of list. 
//
//


void reverse(ListNode*node1, ListNode*node2, int k)
{
    ListNode* prev = NULL;
    ListNode* cur = node2;
    ListNode* next = node2->next;
    
    while (k > 0 && cur)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next)
        {
            next = next->next;
        }
        k--;
    }
    
    node1->next->next = cur;
    node1->next = prev;
    
}

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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode* root = head;

        ListNode*dummynode = new ListNode(0);
        dummynode->next = root; 
        
        ListNode*ret = dummynode;
        
        int k = n-m+1;
        
        int i = 1;
        while(i < m && root)
        {
            dummynode = dummynode->next;
            root = root->next;
            i++;
        }
        
        reverse(dummynode, root, k);
        
        ListNode*temp = ret->next;
        delete ret;
        return temp;
        
    }
};

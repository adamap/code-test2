//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* sortedListToBST_helper(ListNode*head, ListNode*end)
{
    if ( head == end)
    {
        return NULL;
    }
    
    ListNode*fast = head;
    ListNode*slow = head;
     
    while( fast != end && fast->next != end)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
     
    TreeNode* node = new TreeNode(slow->val);
    node->left  = sortedListToBST_helper(head, slow);
    node->right = sortedListToBST_helper(slow->next, end);
    
    return node; 
}
 
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        return sortedListToBST_helper(head, NULL);    
    }
};

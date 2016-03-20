//
//
//
//Given a binary search tree and a node in it, find the in-order successor of that node in the BST. 
//
//Note: If the given node has no in-order successor in the tree, return null. 
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        if (root == NULL)
        {
            return NULL;
        }
  
        TreeNode* prev = NULL;
        while(root && root->val != p->val)
        {
            if ( root->val > p->val)
            {
                prev = root;
                root = root->left;
            }
            else
            {
                root = root->right;  
            }
        }
    
        if ( root == NULL)
        {
            return NULL;
        }
    
        if ( prev == NULL)
        {
            return root->right;
        }
    
        if ( root->right == NULL)
        {
            return prev;
        }
    
        root = root->right;
        while(root->left)
        {
            root = root->left;
        }
    
        return root;  
    }
};

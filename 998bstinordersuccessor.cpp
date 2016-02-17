//Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST



TreeNode* inorderSuccessor2(TreeNode* root, TreeNode* p)
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


TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) 
{
    TreeNode* successor = NULL;
        
    while(root!= NULL && root->val != p->val)
    {
        if ( root->val > p->val )
        {
            successor = root;
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
    if ( root->right == NULL )
    {
        return successor;
    }
    root = root->right;
    while(root->left != NULL)
    {
        root = root->left;
    }
        
    return root;
}
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
        // write your code here
        return inorderSuccessor2(root,  p); 
    }
};

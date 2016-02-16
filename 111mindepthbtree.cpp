




int minDepth_helper(TreeNode* root) 
{
    if ( root == NULL)
    {
        return 0;
    }
    
    if ( root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    
    if ( root->left == NULL )
    {
        return 1+minDepth_helper(root->right);
    }
    if ( root->right == NULL)
    {
        return 1+minDepth_helper(root->left);
    }
    
    
    return 1+min(minDepth_helper(root->left), minDepth_helper(root->right));
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
    int minDepth(TreeNode* root) 
    {
        if ( root == NULL)
        {
            return 0;
        }

        return minDepth_helper(root);
    }
};

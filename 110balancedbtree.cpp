int maxDepth_helper(TreeNode* root) 
{
    if ( root == NULL)
    {
        return 0;
    }
    
    if ( root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    
    return 1+max(maxDepth_helper(root->left), maxDepth_helper(root->right));
}

int isBalanced_helper(TreeNode* root)
{
    if (root == NULL)
    {
        return 1;
    }
    
    int max_depth_left  = maxDepth_helper(root->left);
    int max_depth_right = maxDepth_helper(root->right);
    
    if ( abs(max_depth_left-max_depth_right) > 1)
    {
        return 0;
    }
    
    return (isBalanced_helper(root->left) && isBalanced_helper(root->right));
    
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
    bool isBalanced(TreeNode* root) 
    {
        
        return isBalanced_helper(root);
    }
};

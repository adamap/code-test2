
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
    int maxDepth(TreeNode* root) 
    {
        if ( root == NULL)
        {
            return 0;
        }

        return maxDepth_helper(root);
        
    }
};

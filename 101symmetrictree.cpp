
int isSymmetric_helper(TreeNode* node1, TreeNode* node2)
{
    if ( node1 == NULL || node2 == NULL)
    {
        return (node1==node2);
    }
    
    if (node1->val != node2->val)
    {
        return 0;
    }
    
    return (isSymmetric_helper(node1->left, node2->right) && isSymmetric_helper(node1->right, node2->left));

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
    bool isSymmetric(TreeNode* root) 
    {
        if ( root == NULL)
        {
            return 1;
        }
        return isSymmetric_helper(root->left, root->right);
    }
};

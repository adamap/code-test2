//
//Given a binary tree, find the maximum path sum. 
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
//
//For example:
// Given the below binary tree, 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxPathSum_helper(TreeNode* root, int &maxsum)
{
    if ( root == NULL)
    {
        return 0;
    }
    
    int max_left  = max(0, maxPathSum_helper(root->left, maxsum));
    int max_right = max(0, maxPathSum_helper(root->right, maxsum));
    
    int singlepath = max(max_left, max_right) + root->val;
    int throughpath = max_left + max_right + root->val;
    
    maxsum = max(max(maxsum, singlepath), throughpath);
    
    return singlepath;
    
}
 
 
 
class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
        int maxsum = INT_MIN;
        maxPathSum_helper(root, maxsum);
        
        return maxsum;
    }
};

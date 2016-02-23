//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. 
//For example:
// Given the below binary tree and sum = 22,               5
//              / \
//             4   8
//            /   / \
//          11  13  4
//         /  \      \
//       7    2      1
//   return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
//



int hasPathSum_helper(TreeNode*root, int tempsum, int sum)
{
    if ( root == NULL)
    {
        return 0;
    }
    tempsum += root->val;
    if ( root->left == NULL && root->right == NULL)
    {
        return (tempsum == sum);
    }
    
    return hasPathSum_helper(root->left, tempsum, sum) || hasPathSum_helper(root->right, tempsum, sum);
    
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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        int tempsum = 0;
        return hasPathSum_helper(root, tempsum, sum);
        
    }
};

//
//
//Given a binary tree, flatten it to a linked list in-place. 
//
//For example,
// Given 
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
//
//
//     The flattened tree should look like:
//           1
//            \
//             2
//              \
//               3
//                \
//                 4
//                  \
//                   5
//                    \
//                     6
//
//
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

TreeNode* flatten_helper(TreeNode* root)
{
    if ( root == NULL)
    {
        return NULL;
    }
    
    TreeNode*left = flatten_helper(root->left);
    
    TreeNode*right = flatten_helper(root->right);
    
    root->right = left;
    
    while(left && left->right)
    {
        left= left->right;
    }
    
    if ( left)
    {
        left->right = right;
    }
    else
    {
        if ( right)
        {
            root->right = right;
        }
    }
    
    //dont forget to do following
    root->left = NULL;
    
    return root;
    
}
 
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        TreeNode* ret = flatten_helper(root);
        root = ret;    
    }
};

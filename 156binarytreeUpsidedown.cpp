//
//
//Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root. 
//For example:
// Given a binary tree {1,2,3,4,5},
//     1
//    / \
//   2   3
//  / \
// 4   5
//
//
//
//  return the root of the binary tree [4,5,2,#,#,3,1].
//
//        4
//       / \
//      5   2
//         / \
//        3   1  
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
TreeNode *buldupsidedown_helper(TreeNode *node, TreeNode *&newhead)
{
    if (node == NULL)
    {
        return NULL;
    }
    
    if (node->left == NULL && node->right == NULL)
    {
        newhead = node;
        return node;
    }
    
    TreeNode *right = node->right;
    TreeNode * parent = buldupsidedown_helper(node->left, newhead);
    parent->left = right;
    parent->right = node;
    node->left = node->right = NULL;
    return parent->right;
}

TreeNode * buldupsidedown_it(TreeNode *root)
{
    TreeNode *node = root, *parent = NULL, *right = NULL;
    while (node)
    {
        TreeNode *temp_left = node->left;
        node->left = right;
        TreeNode *temp_right = node->right;
        node->right = parent;
        parent = node;
        right = temp_right;
        node = temp_left;
    }
    
    return parent;
}

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) 
    {
      //  if ( root == NULL)
      //  {
      //    return NULL;
      //  }
      //  TreeNode *newhead;
      //  buldupsidedown_helper(root, newhead);
      //  return newhead;
      return buldupsidedown_it(root);
    }
};

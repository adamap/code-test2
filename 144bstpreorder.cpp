



//Given a binary tree, return the preorder traversal of its nodes' values.
//
//For example:
// Given binary tree {1,#,2,3},
//
//    1
//     \
//      2
//      /
//     3
//
//
//
//   return [1,2,3]. 
//
//   Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>result;
        if ( NULL == root)
        {
            return result;
        }
        stack<TreeNode*>s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode*node = s.top();
            s.pop();
            result.push_back(node->val);
            if ( node->right)
            {
                s.push(node->right);
            }
            
            if ( node->left)
            {
                s.push(node->left);
            }
        }
        return result;        
    }
};



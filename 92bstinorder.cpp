//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example:
// Given binary tree {1,#,2,3},
//
//    1
//    \
//     2
//    /
//   3
//
//
//
//   return [1,3,2]. 
//
//   Note: Recursive solution is trivial, could you do it iteratively?
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>result;
        if ( NULL== root)
        {
            return result;
        }
        stack<TreeNode*>s;

        TreeNode*node = root;
        
        while(node || !s.empty())
        {
            while(node)
            {
                s.push(node);
                node = node->left;
            }
            
            node = s.top();
            s.pop();
            result.push_back(node->val);
            node = node->right;
        }
        
        return result;
    }
};

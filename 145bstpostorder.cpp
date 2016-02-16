//Given a binary tree, return the postorder traversal of its nodes' values.
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
//  return [3,2,1]. 
//
//  Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>result;
        if ( NULL == root)
        {
            return result;
        }
        stack<TreeNode*>s;
        s.push(root);
        
        TreeNode* prev = NULL, *cur = NULL;
        while(!s.empty())
        {
            cur = s.top();    
            if ( !prev || prev->left == cur || prev->right == cur)
            {
                if (cur->left)
                {
                    s.push(cur->left);
                }
                else if ( cur->right)
                {
                    s.push(cur->right);
                }
                else
                {
                    s.pop();
                    result.push_back(cur->val);
                }
            }
            else if (cur->left == prev)
            {
                if ( cur->right)
                {
                    s.push(cur->right);
                }
                else
                {
                    s.pop();
                    result.push_back(cur->val);
                }
            }
            else if (cur->right == prev)
            {
                s.pop();
                result.push_back(cur->val);
            }
            prev = cur;
        }
    }
};

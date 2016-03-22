//
//
//
//Given a binary tree, count the number of uni-value subtrees.
//
//A Uni-value subtree means all nodes of the subtree have the same value.
//
//For example:
// Given binary tree,
//
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
//
//
//       return 4. 
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

int isUnival(TreeNode* root, int val)
{
    if (root == NULL)
    {
        return 1;
    }
    return (root->val == val && isUnival(root->left, val) && isUnival(root->right, val));
} 

void countUnivalSubtrees_helper(TreeNode* root, int &res)
{
    if (NULL == root)
    {
        return ;
    }
    
    if (isUnival(root, root->val))
    {
        ++res;
    }
    
    countUnivalSubtrees_helper(root->left, res);
    countUnivalSubtrees_helper(root->right, res);
    return;
}

int countUnivalSubtrees_iter(TreeNode* root)
{
    if ( root == NULL)
    {
        return 0;
    }
    TreeNode* prev = root;
    unordered_set<TreeNode*>ret;
    stack<TreeNode*>stk;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
  
        if ((cur->left == NULL && cur->right == NULL) || cur->left == prev || cur->right == prev)
        {
            if (!cur->left && !cur->right)
            {
                ret.insert(cur);
            }
            else if (!cur->left && ret.find(cur->right) != ret.end() && cur->right->val == cur->val)
            {
                ret.insert(cur);
            }
            else if (!cur->right && ret.find(cur->left) != ret.end() && cur->left->val == cur->val)
            {
                ret.insert(cur);
            }
            else if (cur->left && cur->right && ret.find(cur->left) != ret.end() && ret.find(cur->right) != ret.end()
                                                        && cur->left->val == cur->val && cur->right->val == cur->val)
            {
                ret.insert(cur);
            }
            stk.pop();
            prev = cur;
        }
        else
        {
            if (cur->right)
            {
                stk.push(cur->right);
            }
            if (cur->left)
            {
                stk.push(cur->left);
            }
        }
    }
    return ret.size();
}

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) 
    {
        //int res = 0;
        //countUnivalSubtrees_helper(root, res);
        //return res;
        
        return countUnivalSubtrees_iter(root);
    }
};

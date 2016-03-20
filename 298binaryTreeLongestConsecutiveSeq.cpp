//
//
//
//Given a binary tree, find the length of the longest consecutive sequence path. 
//
//
//
//The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse). 
//
//For example,
//
//   1
//    \
//     3
//    / \
//   2   4
//        \
//         5
//
//   Longest consecutive sequence path is 3-4-5, so return 3.    
//      2
//       \
//         3
//        / 
//       2    
//      / 
//     1
//
//   Longest consecutive sequence path is 2-3,not3-2-1, so return 2. 
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
void longestConsecutive_helper(TreeNode* cur, TreeNode* prev, int curval, int &result)
{
    if ( cur == NULL)
    {
        return;
    }
    
    if ( cur->val == prev->val+1)
    {
        curval++;
    }
    else
    {
        curval = 1;
    }
    
    if ( result < curval)
    {
        result = curval;
    }
    
    longestConsecutive_helper(cur->left, cur, curval, result);
    longestConsecutive_helper(cur->right, cur, curval, result);
}
 
class Solution {
public:
    int longestConsecutive(TreeNode* root) 
    {
        if ( root == NULL)
        {
            return 0;
        }
        int result = 1;
        longestConsecutive_helper(root, root, 1, result);
        return result;
    }
};

//
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
// Given binary tree {3,9,20,#,#,15,7},
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its bottom-up level order traversal as:
//
//  [
//   [15,7],
//   [9,20],
//   [3]
//  ]
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>>result;
        if ( NULL == root)
        {
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        int cur = 1;
        int next = 0;
        
        while (!q.empty())
        {
            vector<int>set;
            while(cur > 0)
            {
                TreeNode*node = q.front();
                q.pop();
                set.push_back(node->val);
                cur--;
                if ( node->left)
                {
                    q.push(node->left);
                    next++;
                }

                if ( node->right)
                {
                    q.push(node->right);
                    next++;
                }
            }
            if ( set.size() > 0)
            {
                result.push_back(set);
            }
            cur = next;
            next = 0;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};

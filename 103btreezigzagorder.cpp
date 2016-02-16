//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
//  return its zigzag level order traversal as:
//
//  [
//   [3],
//   [20,9],
//   [15,7]
//  ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        if ( NULL == root)
        {
            return result;
        }
        stack< TreeNode*>s_cur;
        stack< TreeNode*>s_next;
        s_cur.push(root);
        int cur = 1;
        int next = 0;
        
        int lefttoright = 1;
        while ( !s_cur.empty())
        {
            vector<int>sets;
            while( cur > 0)
            {
                TreeNode* node = s_cur.top();
                s_cur.pop();
                sets.push_back(node->val);
                cur--;
                
                if (lefttoright == 1)
                {
                    if ( node->left )
                    {
                        s_next.push(node->left);
                        next++;
                    }

                    if ( node->right )
                    {
                        s_next.push(node->right);
                        next++;
                    }
                }
                else
                {
                    if ( node->right )
                    {
                        s_next.push(node->right);
                        next++;
                    }

                    if ( node->left )
                    {
                        s_next.push(node->left);
                        next++;
                    }
                }
            }
            if ( sets.size() > 0)
            {
                result.push_back(sets);
            }
            lefttoright = !lefttoright;
            s_cur = s_next;
            while(!s_next.empty())
            {
                s_next.pop();
            }
            cur = next;
            next = 0;
        }
        
        return result;
    }
};

//
//
//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//For example:
// Given the following binary tree,
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
//
//
//
//  You should return [1, 3, 4]. 
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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        if (NULL == root)
        {
            return result;
        }
 
        queue<TreeNode *>q;
        q.push(root);
        int cur = 1, next = 0;
 
        while (!q.empty())
        {
            while (cur > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                cur--;
                if (cur == 0)
                {
                    result.push_back(node->val);
                }
                if (node->left)
                {
                    q.push(node->left);
                    next++;
                }
                if (node->right)
                {
                    q.push(node->right);
                    next++;
                }
            }
  
            cur = next;
            next = 0;
        }
        return result;
    }
};

//
//
//Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target. 
//
//Note:
//
//Given target value is a floating point.
//You may assume k is always valid, that is: k ¡ total nodes.
//You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
//
//
//Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)? 
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
    vector<int> closestKValues(TreeNode* root, double target, int k) 
    {
        queue<int>q;
        stack<TreeNode* >stk;
        
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            
            if (q.size() < k)
            {
                q.push(cur->val);
            }
            else
            {
                int first = q.front();
                if ( abs(first-target) > abs(cur->val - target) )
                {
                    q.pop();
                    q.push(cur->val);
                }
                else
                {
                    break;
                }
            }
            
            if ( cur->right)
            {
                cur = cur->right;
                while(cur)
                {
                    stk.push(cur);
                    cur = cur->left;
                }
            }
        }
        vector<int>result;
        while(!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};

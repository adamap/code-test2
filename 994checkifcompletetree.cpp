//
//
//Check a binary tree is completed or not. A complete binary tree is a binary tree that every level is completed filled except the deepest level. In the deepest level, all nodes must be as left as possible. See more definition
//


//todo recursion

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     */
    bool isComplete(TreeNode* root) 
    {
        // Write your code here
        if(NULL == root)
        {
            return 1;
        }
        queue<TreeNode*>s;
        s.push(root);
        int isNULL = 0;
        int cur = 1;
        int next = 0;
        while(!s.empty())
        {
            while( cur > 0)
            {
                TreeNode*node = s.front();
                s.pop();
                cur--;
            
                if ((1 == isNULL) && ( node->left != NULL || node->right != NULL))
                {
                    return 0;
                }
                
                if ( node->left == NULL && node->right != NULL)
                {
                    return 0;
                }
                if ( node->left == NULL || node->right == NULL)
                {
                    isNULL = 1;
                }
            
                if (node->left)
                {
                    next++;
                    s.push(node->left);
                }
            
                if (node->right)
                {
                    next++;
                    s.push(node->right);
                }
            }
            cur = next;
            next = 0;
            
        }
        return 1;
    }
};

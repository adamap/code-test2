//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note: 
// You may assume k is always valid, 1 ¡ k ¡ BST's total elements.
//
// Follow up:
//  What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
    int kthSmallest(TreeNode* root, int k) 
    {
        
        stack<TreeNode*>st;
        
        TreeNode*node = root;
        
        int index = 1;
        int ret = 0;
        while(node || !st.empty())
        {
            while(node)
            {
                st.push(node);
                node = node->left;
            }
            
            node = st.top();
            if ( index ==  k)
            {
                ret = node->val;
                break;
            }
            index ++;
            
            st.pop();
            node = node->right;
        }
        
        return ret;
        
    }
};

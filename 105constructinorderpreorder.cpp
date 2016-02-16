//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
// You may assume that duplicates do not exist in the tree. 

TreeNode* buildTree_helper(vector<int>&inorder, int starti, int endi, vector<int>&preorder, int startp, int endp)
{
    if ( starti > endi)
    {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[startp]);
    if ( startp == endp)
    {
        return root;
    }
    
    int val = preorder[startp];
    int i;
    for ( i = starti; i <= endi; i++)
    {
        if ( inorder[i] == val)
        {
            break;
        }
    }
    
    int len = i-starti;
    
    root->left = buildTree_helper(inorder, starti, i-1, preorder, startp+1, startp+len);
    root->right = buildTree_helper(inorder, i+1, endi, preorder, startp+len+1, endp);
    
    return root;
}

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
         if (0 == inorder.size() || 0 == preorder.size() || preorder.size() != inorder.size())
        {
            return NULL;
        }
        
        int n = inorder.size();
        TreeNode* root = buildTree_helper(inorder, 0, n-1, preorder, 0, n-1);
    }
};


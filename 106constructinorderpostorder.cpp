//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
// You may assume that duplicates do not exist in the tree. 
//



TreeNode* buildTree_helper(vector<int>&inorder, int starti, int endi, vector<int>&postorder, int startp, int endp)
{
    if ( starti > endi)
    {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(postorder[endp]);
    if ( startp == endp)
    {
        return root;
    }
    
    int val = postorder[endp];
    int i;
    for ( i = starti; i <= endi; i++)
    {
        if ( inorder[i] == val)
        {
            break;
        }
    }
    
    int len = i-starti;
    
    root->left = buildTree_helper(inorder, starti, i-1, postorder, startp, startp+len-1);
    root->right = buildTree_helper(inorder, i+1, endi, postorder, startp+len, endp-1);
    
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        
        if (0 == inorder.size() || 0 == postorder.size() || postorder.size() != inorder.size())
        {
            return NULL;
        }
        
        int n = inorder.size();
        TreeNode* root = buildTree_helper(inorder, 0, n-1, postorder, 0, n-1);
    }
};

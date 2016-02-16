

long long calc_leftmax(TreeNode* root)
{
    int max = LLONG_MIN;
    
    while(root)
    {
        max = root->val;
        root = root->right;
    }
    
    return max;
}

long long calc_rightmin(TreeNode* root)
{
    int min = LLONG_MAX;
    
    while(root)
    {
        min = root->val;
        root = root->left;
    }
    
    return min;
}

int isValidBST_helper2(TreeNode* root)
{
    if ( root == NULL)
    {
        return 1;
    }
    
    long long left_max  = calc_leftmax(root->left);
    long long right_min = calc_rightmin(root->right);
    
    if ( root->val > left_max && root->val < right_min)
    {
        return (isValidBST_helper2(root->left) && isValidBST_helper2(root->right));
    }
    
    return 0;
}

int isValidBST_helper(TreeNode* root, long long min, long long max)
{
    
    if ( NULL == root)
    {
        return 1;
    }
    
    if ( root->val > min && root->val < max)
    {
        return isValidBST_helper(root->left, min, root->val) && isValidBST_helper(root->right, root->val, max);
    }
    return 0;    
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
    bool isValidBST(TreeNode* root) 
    {
        long long min = LLONG_MIN, max = LLONG_MAX;
        return isValidBST_helper(root, min, max);    
        
        //return isValidBST_helper2(root);
    }
};

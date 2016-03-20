//
//
//
//Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target. 
//
//Note:
//
//Given target value is a floating point.
//You are guaranteed to have only one unique value in the BST that is closest to the target.
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

double fabs_calc(double i)
{
    return (i<0)?(-i):i;
}

void closestValue_helper(TreeNode* root, double target, double &mindiff, int &node_val)
{
    if (root == NULL)
    {
        return;
    }
    if ( abs((double)root->val-target) < mindiff)
    {
        mindiff = fabs_calc((double)root->val-target);
        node_val = root->val; 
    }
    
    if (target > (double)root->val )
    {
        closestValue_helper(root->right, target, mindiff, node_val);
    }
    else
    {
        closestValue_helper(root->left, target, mindiff, node_val);
    }
     
}

class Solution {
public:
    int closestValue(TreeNode* root, double target) 
    {
        double mindiff = 1.79769e+308;
        int node_val = root->val;
        
        closestValue_helper(root, target, mindiff, node_val);
        
        return node_val;
    }
};

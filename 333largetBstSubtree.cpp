//
//
//Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
//
//Note:
// A subtree must include all of its descendants.
//  Here's an example:
//
//      10
//      / \
//     5  15
//    / \   \ 
//   1   8   7
//
//  The Largest BST Subtree in this case is the highlighted one. 
//  The return value is the subtree's size, which is 3. 
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
 
int checkBST(TreeNode *root, int min, int max)
{
    if (root == NULL)
    {
        return 0;
    }
    if ((root->val < min) || (root->val > max))
    {
        return -1;
    }
    
    int left  = checkBST(root->left, min, root->val);
    int right = checkBST(root->right, root->val, max);
    
    if (left == -1 || right == -1)
    {
        return -1;
    }
    return 1 + left + right;
}

void maxsub_BST_helper(TreeNode *root, int &res)
{
    if (root == NULL)
    {
        return;
    }
    int ret = checkBST(root, INT_MIN, INT_MAX);
    if ( ret != -1)
    {
        if(ret > res)
        {
            res = ret;
        }
        return;
    }
    maxsub_BST_helper(root->left, res);
    maxsub_BST_helper(root->right, res);
} 

int max_calc(int a, int b)
{
    return (a>b)?a:b;
}

int maxsub_BST2_helper(TreeNode *root, int &min, int &max, int &res)
{
    if (root == NULL)
    {
        return 1;
    }
    int left_min = INT_MIN, right_min = INT_MIN, left_max = INT_MAX, right_max = INT_MAX;
    int res_left = 0, res_right = 0;
    int left = maxsub_BST2_helper(root->left,  left_min,  left_max,  res_left);
    int right = maxsub_BST2_helper(root->right, right_min, right_max, res_right);
 
    if (left && right)
    {
        if (((!root->left) || (root->left && left_max < root->val)) && ((!root->right) || (root->right && right_min > root->val)))
        {
            res = res_left + res_right + 1;
            min = (root->left)  ? left_min : root->val;
            max = (root->right) ? right_max : root->val;
            return 1;
        }
    }
    res = max_calc(res_left, res_right);
    return 0;
}


class Solution {
public:
    int largestBSTSubtree(TreeNode* root) 
    {
        //int res = 0;
        //maxsub_BST_helper(root, res);
        //return res;
        
        int min = INT_MIN, max = INT_MAX, res = 0;
        maxsub_BST2_helper(root, min, max, res);
        return res;
    }
};

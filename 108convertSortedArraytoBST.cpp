//
//
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
TreeNode*sortedArrayToBST_helper(vector<int>& nums, int start, int end)
{
    if ( start > end)
    {
        return NULL;
    }
    
    int mid = start+(end-start)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    
    root->left  = sortedArrayToBST_helper(nums, start, mid-1);
    root->right = sortedArrayToBST_helper(nums, mid+1, end);
    
    return root;
    
}
 
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n = nums.size();
        
        TreeNode* ret = sortedArrayToBST_helper(nums, 0, nums.size()-1);
    
        return ret;    
    }
};

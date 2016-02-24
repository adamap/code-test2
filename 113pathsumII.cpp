//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum. 
//For example:
// Given the below binary tree and sum = 22,              
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//        7    2  5   1
//
//       return
//
//    [
//     [5,4,11,2],
//     [5,8,4,5]
//    ]
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
 
void  pathSum_helper(TreeNode* root, int target, int tempsum, vector<int>set, vector<vector<int>>&result)
{
    if ( root == NULL)
    {
        return;
    }
    
    set.push_back(root->val);
    tempsum += root->val;
    if ( root->left == NULL && root->right == NULL)
    {
        if ( tempsum == target)
        {
            result.push_back(set);
            return;
        }
    }
    
    pathSum_helper(root->left, target, tempsum, set, result);
    pathSum_helper(root->right, target, tempsum, set, result);
}


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>>result;
        vector<int>set;
        int temp = 0;
        pathSum_helper(root, sum, temp, set, result);
        return result;
    }
};                                                                      

//Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
// Given n = 3, your program should return all 5 unique BST's shown below. 
//    1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//

vector<TreeNode*>generateTrees_helper(int start, int end)
{
    vector<TreeNode*> result;
    if ( start > end)
    {
        result.push_back(NULL);
        return result;
    }
    
    for ( int i = start;  i <= end; i++)
    {
        vector<TreeNode*>leftsets  = generateTrees_helper(start, i-1);
        vector<TreeNode*>rightsets = generateTrees_helper(i+1,  end);
        
        for ( int j = 0; j < leftsets.size(); j++)
        {
            for ( int k = 0; k < rightsets.size(); k++)
            {
                TreeNode*root = new TreeNode(i);
                root->left  = leftsets[j];
                root->right = rightsets[k];
                result.push_back(root);
            }
        }
    }
    return result;    
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
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*>ret;
        if ( 0 == n)
        {
            return ret;
        }
        return generateTrees_helper(1, n);
    }
};                    

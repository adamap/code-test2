//Given a binary tree, return all root-to-leaf paths. 
//
//For example, given the following binary tree: 
//
//
//      1
//    /   \
//    2     3
//     \
//       5
//
//
//
//       All root-to-leaf paths are: 
//       ["1->2->5", "1->3"]

void binaryTreePaths_helper(TreeNode*root, string setstr, vector<string> &result)
{
    if ( root == NULL)
    {
        return;
    }
    
    ostringstream os;
    os<<root->val;
    setstr.append(os.str());
    if ( root->left == NULL && root->right == NULL)
    {
        result.push_back(setstr);
        return;
    }
    setstr.append("->");
        
    binaryTreePaths_helper(root->left, setstr, result);
    binaryTreePaths_helper(root->right, setstr, result);
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        string setstr;
        binaryTreePaths_helper(root, setstr, result);
        
        return result;
    }
};

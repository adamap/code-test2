//Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in ascending order.
//Example 
//
//If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].
//      20
//     /  \
//     8   22
//   /  \
//  4   12
//






void searchRange1_helper(TreeNode* root, int k1, int k2, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    
    if ( root->val < k1)
    {
        searchRange1_helper(root->right, k1, k2, result);
        return;
    }
    
    if ( root->val > k2)
    {
        searchRange1_helper(root->left, k1, k2, result);
        return;
    }
    
    result.push_back(root->val);
    searchRange1_helper(root->right, k1, k2, result);
    searchRange1_helper(root->left, k1, k2, result);
    
}

vector<int> searchRange1(TreeNode* root, int k1, int k2) 
{
    vector<int> result;
    if ( root == NULL)
    {
        return result;
    }
    
    searchRange1_helper( root,  k1,  k2, result);
    
    sort(result.begin(), result.end());
    return result;
}





/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
void searchRange_helper(TreeNode* root, int k1, int k2, vector<int>&result)  
{
    if (root == NULL)
    {
        return;
    }
    
    if ( root->val < k1)
    {
        searchRange_helper(root->right, k1, k2, result);
        return;
    }
    
    if ( root->val > k2)
    {
        searchRange_helper(root->left, k1, k2, result);
        return;
    }
    
    result.push_back(root->val);
    searchRange_helper(root->right, k1, k2, result);
    searchRange_helper(root->left, k1, k2, result);


    return;
}
 
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) 
    {
        // write your code here
        
        //vector<int>result;
        //searchRange_helper(root, k1, k2, result);
        //sort(result.begin(), result.end());
        //return result;
        return searchRange1( root,  k1,  k2); 

    }
};


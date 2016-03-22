//
//
//
//
//Given an integer array with no duplicates. A max tree building on this array is defined as follow:
//The root is the maximum number in the array
//The left subtree and right subtree are the max trees of the subarray divided by the root number.
//
//Construct the max tree by the given array.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example
//
//
// Given [2, 5, 6, 0, 3, 1], the max tree constructed by this array is:
//     6
//    / \
//   5   3
//  /   / \
// 2   0   1
//
//
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
//think about mintree, same concept

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        
        stack<TreeNode *>s;
        
        for (int i = 0; i < A.size(); i++)
        {
            TreeNode *temp = new TreeNode(A[i]);
            
            while( !s.empty() && s.top()->val < A[i]  )
            {
                temp->left = s.top();
                s.pop();
            }
            if ( !s.empty())
            {
                s.top()->right = temp;
            }
            s.push(temp);
        }
        
        TreeNode *root; 
        while( !s.empty())
        {
            root = s.top();
            s.pop();
        }
        
        return root;
    }

};

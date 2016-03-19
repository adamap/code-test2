//
//
//
//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night. 
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police. 
//
//Example 1:
//
//     3
//    / \
//   2   3
//    \   \ 
//     3   1
//
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7. 
//
// Example 2:
//
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
//
// Maximum amount of money the thief can rob = 4 + 5 = 9. 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct node
{
    int prev;
    int cur;
    node()
    {
        prev = 0;
        cur = 0;
    }
};

node* rob_helper(TreeNode* root)
{
    if (root == NULL)
    {
        return new node;
    }
    
    node*node_left = rob_helper(root->left);
    node*node_right = rob_helper(root->right);
    
    node *curnode = new node;
    
    curnode->prev = node_left->cur + node_right->cur;
    curnode->cur = max(curnode->prev, node_left->prev+ node_right->prev + root->val);
    return curnode;
    
}
 
class Solution {
public:
    int rob(TreeNode* root) 
    {
       node* curnode = rob_helper(root);
       
       return curnode->cur;
    }
};

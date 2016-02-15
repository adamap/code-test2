//Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST. 
//
//According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)." 
//        _______6______
//               /              \
//                   ___2__          ___8__
//                      /      \        /      \
//                         0      _4       7       9
//                                  /  \
//                                           3   5
//
//
//                                           For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.



int find_path(TreeNode* root, TreeNode*p, vector<TreeNode*>&path)
{
    if (root == NULL)
    {
        return 0;
    }
    
    path.push_back(root);
    if ( root == p)
    {
        return 1;
    }
    
    if ( root->left && 1 == find_path(root->left, p, path))
    {
        return 1;
    }
    if ( root->right && 1 == find_path(root->right, p, path))
    {
        return 1;
    }
    ///////
    path.pop_back();
    return 0;
}

//bst we can simplify path search without using recursion

int find_path1(TreeNode* root, TreeNode*p, vector<TreeNode*>&path)
{
    while( root)
    {
        path.push_back(root);
        if ( root->val == p->val)
        {
            return 1;
        }
        else if ( root->val < p->val)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*>pathp, pathq;
        //int findpPath = find_path(root, p, pathp);
        //int findqPath = find_path(root, q, pathq);
        
        int findpPath = find_path1(root, p, pathp);
        int findqPath = find_path1(root, q, pathq);
        
        if (0 == findpPath || 0 == findqPath)
        {
            return NULL;
        }
        
        int i = 0, j = 0;
        while(i < pathp.size() && j < pathq.size() && pathp[i] == pathq[j])
        {
            i++;
            j++;
        }
        return pathp[i-1];
        
    }
};

//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. 
//
//According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)." 
//        _______3______
//               /              \
//                   ___5__          ___1__
//                      /      \        /      \
//                         6      _2       0       8
//                                  /  \
//                                           7   4
//
//
//                                           For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


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

TreeNode* lowestCommonAncestor_checkpath(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    vector<TreeNode*>pathp, pathq;
    int findpPath = find_path(root, p, pathp);
    int findqPath = find_path(root, q, pathq);
        
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


TreeNode* lowestCommonAncestor_rec(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root==NULL || root == p || root == q)
    {
        return root;
    }
    
    TreeNode*left  = lowestCommonAncestor_rec(root->left, p, q);
    TreeNode*right = lowestCommonAncestor_rec(root->right, p, q);
    
    if ( left != NULL && right != NULL)
        return root;
        
    if ( left != NULL)
        return left;
        
    if ( right != NULL)
        return right;
    
    return NULL;    
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
      return lowestCommonAncestor_rec( root,  p,  q);
    }
};

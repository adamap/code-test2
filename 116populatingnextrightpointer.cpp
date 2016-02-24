//Given a binary tree 
//    struct TreeLinkNode {
//    TreeLinkNode *left;
//    TreeLinkNode *right;
//    TreeLinkNode *next;
//    }
//
//
//
//  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//  Initially, all next pointers are set to NULL.
//
//  Note: 
// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//
//
//  For example,
//  Given the following perfect binary tree,
//
//                1
//               /  \
//              2    3
//             / \  / \
//            4  5  6  7
//
//
//
//   After calling your function, the tree should look like:
//
//          1 -> NULL
//         /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL
//
//    

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
void connect_bfs(TreeLinkNode *root)  
{
    if ( NULL == root)
    {
        return ;
    }
    queue<TreeLinkNode *>q;
    q.push(root);
    root->next = NULL;
        
    int cur = 1; 
    int next = 0;
        
    while(!q.empty())
    {
        while(cur > 0)
        {
            TreeLinkNode *node = q.front();
            q.pop();
            cur--;
        
            if ( node->left)
            {
                next++;
                node->left->next = node->right;
                q.push(node->left);
            }
            if ( node->right)
            {
                next++;
                if (node->next)
                {
                    node->right->next = node->next->left;
                }
                else
                {
                    node->right->next = NULL;
                }
                q.push(node->right);
            }
        }
        cur = next;
        next = 0;
    } 
}

void connect_dfs(TreeLinkNode *root)  
{
    if ( root == NULL || root->left == NULL || root->right == NULL )
    {
        return;
    }
    
    root->left->next = root->right;
    root->right->next = (root->next)?root->next->left:NULL;
    connect_dfs(root->left);
    connect_dfs(root->right);
}


 
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        //connect_bfs(root);
        connect_dfs(root);
    }
};











                                                                                     

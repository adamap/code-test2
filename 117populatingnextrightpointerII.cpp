//Follow up for problem "Populating Next Right Pointers in Each Node".

//What if the given tree could be any binary tree? Would your previous solution still work?

//Note: 
//You may only use constant extra space.


//For example,
// Given the following binary tree,

//         1
//       /  \
//      2    3
//     / \    \
//    4   5    7



//After calling your function, the tree should look like:

//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \    \
//    4-> 5 -> 7 -> NULL

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
    vector<TreeLinkNode *>q;
    q.push_back(root);
    root->next = NULL;
        
    int cur = 1; 
    int next = 0;
        
    while(!q.empty())
    {
        while(cur > 0)
        {
            TreeLinkNode *node = q[0];
            q.erase(q.begin());
            cur--;
        
            if ( node->left)
            {
                next++;
                if ( node->right)
                {
                    node->left->next = node->right;
                }
                else
                {
                    TreeLinkNode *tempnode = node;
                    while(tempnode->next && tempnode->next->left == NULL && tempnode->next->right == NULL)
                    {
                        tempnode = tempnode->next;
                    }
                    
                    if (tempnode->next == NULL)
                    {
                        node->left->next = NULL;
                    }
                    else if (( tempnode->next->left == NULL) && (tempnode->next->right == NULL))
                    {
                        node->left->next = NULL;
                    }
                    else
                    {
                        if (tempnode->next->left)
                        {
                            node->left->next = tempnode->next->left;
                        }
                        else
                        {
                            node->left->next = tempnode->next->right;
                        }
                    }
                }
                q.push_back(node->left);
            }
            if ( node->right)
            {
                next++;
                TreeLinkNode *tempnode = node;
                while(tempnode->next && tempnode->next->left == NULL && tempnode->next->right == NULL)
                {
                    tempnode = tempnode->next;
                }
                    
                if (tempnode->next == NULL)
                {
                    node->right->next = NULL;
                }
                else if (( tempnode->next->left == NULL) && (tempnode->next->right == NULL))
                {
                    node->right->next = NULL;
                }
                else
                {
                    if (tempnode->next->left)
                    {
                        node->right->next = tempnode->next->left;
                    }
                    else
                    {
                        node->right->next = tempnode->next->right;
                    }
                }
                q.push_back(node->right);
            }
        }
        cur = next;
        next = 0;
    } 
} 
 
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        connect_bfs(root);  
    }
};














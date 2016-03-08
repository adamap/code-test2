//
//
//
//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
 
int  calcdepth(TreeNode* root)
{
    if ( root == NULL)
    {
        return 0;
    }
    
    return 1+max(calcdepth(root->left), calcdepth(root->left));
}

int countNodes_levelorder(TreeNode* root)
{
    if ( root == NULL)
    {
        return 0;
    }
    int ret = 0;
    queue<TreeNode*>q;
    q.push(root);

    int cur = 1,  next = 0;
        
    while(!q.empty())
    {
        while(cur > 0)
        {
            TreeNode* node = q.front();
            q.pop();
            ret ++;
            cur--;
                
            if ( node->left)
            {
                next++;
                q.push(node->left);
            }
                
            if ( node->right)
            {
                next++;
                q.push(node->right);
            }
        }
        cur = next;
        next = 0;
    }
        
    return ret;
}

int countNodes_rec(TreeNode* root)
{
    if ( root == NULL)
    {
        return 0;
    }
    int left_depth = 0, right_depth = 0;
    
    TreeNode* templeft = root, *tempright = root;
    
    while(templeft)
    {
        left_depth++;
        templeft = templeft->left;
    }
    while(tempright)
    {
        right_depth++;
        tempright = tempright->right;
    }
    
    // if it is full tree, its node numbers is 2^depth-1
    if ( right_depth == left_depth)
    {
        return pow(2, right_depth)-1;
    }
    
    return 1+countNodes_rec(root->left)+countNodes_rec(root->right);
    
}

  TreeNode* getNode(TreeNode* root, int path, int depth) 
  {
        while (depth-- && root) 
        {
            if (path & (1 << depth)) 
            {
                root = root->right;
            } 
            else 
            {
                root = root->left;
            }
        }
        return root;
    }

  int countNodes_bs(TreeNode* root) 
  {
        int depth = 0;
        TreeNode* node = root;
        
        while (node) 
        {
            depth++;
            node = node->left;
        }
        if (depth == 0) 
        {
            return 0;
        }
        int left = 0, right = (1 << (depth - 1)) - 1;
        
        while (left <= right) 
        {
            int mid = (left + right) >> 1;
            if (getNode(root, mid, depth - 1)) 
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }
        return (1 << (depth - 1)) + right;
    }


class Solution {
public:
    int countNodes(TreeNode* root) 
    {
        //return countNodes_levelorder(root);
        //return countNodes_rec(root);
        return countNodes_bs(root);
    }
};

//Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
//
//Credits:

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *>s;
    TreeNode *curNode;
public:
    BSTIterator(TreeNode *root) 
    {
        curNode = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return (curNode || !s.empty());
    }

    /** @return the next smallest number */
    int next() 
    {
        while(curNode)
        {
            s.push(curNode);
            curNode = curNode->left;
        }
        
        curNode = s.top();
        int ret = curNode->val;
        s.pop();
        curNode = curNode->right;
        return ret;
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

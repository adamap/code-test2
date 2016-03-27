//
//
//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure. 
//Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
//
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

/*  optimized in Java code , but still O(n) space becuase of recursion

public class Solution {
    private TreeNode firstElement = null;
    private TreeNode secondElement = null;
    private TreeNode lastElement = new TreeNode(Integer.MIN_VALUE); 
    
    private void traverse(TreeNode root) {
        if (root == null) {
            return;
        }
        traverse(root.left);
        if (firstElement == null && root.val < lastElement.val) {
            firstElement = lastElement;
        }
        if (firstElement != null && root.val < lastElement.val) {
            secondElement = root;
        }
        lastElement = root;
        traverse(root.right);
    }
    
    public void recoverTree(TreeNode root) {
        // traverse and get two elements
        traverse(root);
        // swap
        int temp = firstElement.val;
        firstElement.val = secondElement.val;
        secondElement.val = temp;
    }
}*/


class Solution {
    vector<TreeNode*> list;  
    vector<int > vals;  
    
public:
    void InOrderTravel(TreeNode* node, vector<TreeNode*>& list, vector<int>& vals)  
    {
        if(node == NULL) return;
        InOrderTravel(node->left, list, vals);  
        list.push_back(node);  
        vals.push_back(node->val);  
        InOrderTravel(node->right, list, vals);            
    }
    void recoverTree(TreeNode* root) 
    {
        InOrderTravel(root, list, vals);  
        sort(vals.begin(), vals.end());  
        for(int i =0; i< list.size(); i++)  
        {
            list[i]->val = vals[i];  
        }
    }
};

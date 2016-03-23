//
//
//Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
//
//If two nodes are in the same row and column, the order should be from left to right.
//
//Examples:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
//  return its vertical order traversal as:
//
//       [
//        [9],
//        [3,15],
//        [20],
//        [7]
//       ]
//
//
//
//   Given binary tree [3,9,20,4,5,2,7],
//
//         _3_
//        /   \
//       9    20
//      / \   / \
//     4   5 2   7
//
//
//
//   return its vertical order traversal as:
//      [
//        [4],
//        [9],
//        [3,5,2],
//        [20],
//        [7]
//      ]
//
//
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
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        vector<vector<int> > result;
 
        if (NULL == root)
        {
            return result;
        }
 
        queue<pair<int, TreeNode *>>q;
        map<int, vector<int>>map_ret;
        q.push(make_pair(0, root));
 
        int cur = 1, next = 0;
        int min_index = INT_MAX, max_index = INT_MIN;
 
        while (!q.empty())
        {
            while (cur > 0)
            {
                pair<int, TreeNode *> p_node = q.front();
                q.pop();
                cur--;
                int index = p_node.first;
                min_index = min(min_index, index);
                max_index = max(max_index, index);
                TreeNode *node = p_node.second;
                map_ret[index].push_back(node->val);
   
                if (node->left)
                {
                    q.push(make_pair(index-1, node->left));
                    next++;
                }
                if (node->right)
                {
                    q.push(make_pair(index + 1, node->right));
                    next++;
                }
            }
            cur = next;
            next = 0;
        }
        for (int i = min_index; i <= max_index; i++)
        {
            result.push_back(map_ret[i]);
        }
        return result;
        
    }
};

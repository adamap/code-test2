//
//
//
//
//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. 
//
//Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//For example, you may serialize the following tree 
//    1
//   / \
//  2   3
//     / \
//    4   5
//
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself. 
//
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless. 
//
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string ret;
        
        queue<TreeNode*>q;

        if (root == NULL)
        {
          return ret;
        }

        q.push(root);
        int cur = 1, next = 0;

        while (!q.empty())
        {
          while (cur > 0)
         {
           TreeNode* node = q.front();
           q.pop();
           cur--;

           if (node)
           {
             int val = node->val;
             ostringstream os;
             os << val;
             ret.append(os.str());
             ret.push_back(',');
           }
           else
           {
             ret.append("#,");
             continue;
           }

           q.push(node->left);
           next++;

           q.push(node->right);
           next++;
         }
         cur = next;
         next = 0;
       }

       ret.pop_back();
       return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string>ret_set;

        int i = 0, j = 0;

        while (j < data.size())
        {
          if (data[j] == ',')
          {
            ret_set.push_back(data.substr(i, j - i));
            j++;
            i = j;
          }
          else
          {
            j++;
          }
       }
       if (i!= j)
       {
         ret_set.push_back(data.substr(i, j - i));
       }
       if (ret_set.size() == 0)
       {
         return NULL;
       }

       int temp;
       istringstream is(ret_set[0]);
       is >> temp;

       TreeNode* root = new TreeNode(temp);

       queue<TreeNode*>q;
       q.push(root);

       i = 1;
       while (i < ret_set.size())
       {
         TreeNode* node = q.front(); 
         q.pop();

        if (node == NULL)
        {
          continue;
        }
        string substr = ret_set[i];

        if (substr == "#")
        {
          q.push(NULL);
        }
        else
        {
          int temp;
          istringstream is(substr);
          is >> temp;
          node->left = new TreeNode(temp);
          q.push(node->left);
        }
        i++;
        substr = ret_set[i];
        if (substr == "#")
        {
          q.push(NULL);
        }
        else
        {
          int temp;
          istringstream is(substr);
          is >> temp;
          node->right = new TreeNode(temp);
          q.push(node->right);
        }

        i++;
      }

      return root;
    }
};


//pre-order binary tree serialization
string serialize(TreeNode* root) 
{
  string ret;
  stack<TreeNode*>stk;

  if (root == NULL)
  {
    return ret;
  }

  stk.push(root);

  while (!stk.empty())
  {
    TreeNode* node = stk.top();
    stk.pop();

    int val = node->val;
    ostringstream os;
    os << val;
    ret.append(os.str());
    ret.push_back(',');
    if (node->left == NULL)
    {
      ret.append("#");
      ret.push_back(',');

    }
    if (node->left == NULL)
    {
      ret.append("#");
      ret.push_back(',');
    }

    if (node->right)
    {
      stk.push(node->right);
    }
    if (node->left)
    {
      stk.push(node->left);
    }
  }
  ret.pop_back();
  return ret;
}

void serialize_rec(TreeNode* root, string &ret)
{
  if (root == NULL)
  {
    ret.append("#,");
    return;
  }

  ostringstream os;
  os << root->val;
  ret.append(os.str());
  ret.push_back(',');

  serialize_rec(root->left, ret);
  serialize_rec(root->right, ret);
}


TreeNode * deserialize_rec(vector<string> set, int &index)
{
  if (index >= set.size())
  {
    return NULL;
  }
  string s = set[index];
  if (s == "#")
  {
    return NULL;
  }

  int temp;
  istringstream is(s);
  is >> temp;

  TreeNode *node = new TreeNode(temp);
  index++;
  node->left = deserialize_rec(set, index);
  index++;
  node->right = deserialize_rec(set, index);

  return node;
}

TreeNode * preorder_deserialize_rec(string str)
{
  vector<string>ret_set;

  int i = 0, j = 0;

  while (j < str.size())
  {
    if (str[j] == ',')
    {
      ret_set.push_back(str.substr(i, j - i));
      j++;
      i = j;
    }
    else
    {
      j++;
    }
  }
  ret_set.push_back(str.substr(i, j - i));

  int index = 0;

  TreeNode *root1 = deserialize_rec(ret_set, index);

  return root1;

}



// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

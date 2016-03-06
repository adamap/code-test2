//
//
//One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//          _9_
//         /   \
//        3     2
//       / \   / \
//      4   1  #  6
//     / \ / \   / \
//    #  # # #   # #
//
//
//               For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node. 
//
//               Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//
//               Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
//               You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
//               Example 1:
//               "9,3,4,#,#,1,#,#,2,#,6,#,#"
//               Return true
//
//               Example 2:
//               "1,#"
//               Return false
//
//               Example 3:
//               "9,#,#,1"
//               Return false


class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
      vector<string>strset;

      int i = 0, j = 0;

      while (j < preorder.size())
      {
        if (preorder[j] != ',')
        {
          j++;
        }
        else
        {
          string substr = preorder.substr(i, j - i);
          strset.push_back(substr);
          j++;
          i = j;
        }
      }
      strset.push_back(preorder.substr(i, j - i));

      if (strset.size() == 0)
      {
        return 0;
      }

      vector<string>stk;
      stk.push_back(strset[0]);

      for (int i = 1; i < strset.size(); i++)
      {
        if (strset[i] == "#")
        {
          stk.push_back(strset[i]);
          while (stk.size() >=3 && stk[stk.size() - 1] == "#" && stk[stk.size() - 2] == "#" && stk[stk.size() - 3] != "#")
          {             
            stk.erase(stk.end()-1);
            stk.erase(stk.end()-1);
            stk.erase(stk.end()-1);
            stk.push_back("#");
          }
       }
       else 
       {
         stk.push_back(strset[i]);
       }
     }

     return (stk.size() == 1 && stk[0] == "#");
    }
};



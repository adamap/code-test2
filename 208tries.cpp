//
//Implement a trie with insert, search, and startsWith methods. 
//
//Note:
// You may assume that all inputs are consist of lowercase letters a-z. 
//
//
//
// Subscribe to see which companies asked this question
//
//
// Show Tags
// 

class TrieNode {
public:
    unordered_map<char, struct TrieNode*>children;
    int count;
    // Initialize your data structure here.
    TrieNode() {
        count = 0;
    }
};

class Trie {
    
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
      root->count++;
      TrieNode *nextnode = root;
      for (int i = 0; i < word.size(); i++)
      {
        if (nextnode->children.find(word[i]) == nextnode->children.end())
        {   
          struct TrieNode* newtries = new TrieNode();
          nextnode->children[word[i]] = newtries;
        }
        nextnode = nextnode->children[word[i]];
      }
      nextnode->count = root->count;
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
       TrieNode *nextnode = root;
       for (int i = 0; i < word.size(); i++)
       {
         if (nextnode->children.find(word[i]) != nextnode->children.end())
         {
           nextnode = nextnode->children[word[i]];
         }
         else
         {
           return 0;
         }
      }   
      if (nextnode->count != 0)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        TrieNode *nextnode = root;
        for (int i = 0; i < prefix.size(); i++)
        {
          if (nextnode->children.find(prefix[i]) != nextnode->children.end())
          {
            nextnode = nextnode->children[prefix[i]];
          } 
          else
          {
            return 0;
          }
        }
        return 1;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key"); 

// practice, print out all tries words and delete one word from tries dict

int isleafnode(tries1 *node)
{
  if ( 0 != node->count)
  {
    return 1;
  }
  return 0;
}

int isTerminateNode(tries1 *node)
{
  if ( 0 == node->children.size())
  {
    return 1;
  }
  return 0;
}
void printtries_dfs(tries1 *tries_root, string set, vector<string>&result)
{
   if ( 1 == isleafnode(tries_root))
  { 
    result.push_back(set);
  }
  if ( 1 == isTerminateNode(tries_root))
  {
    return;
  }
  unordered_map<char, struct tries1*>::iterator it;
  for ( it = tries_root->children.begin(); it != tries_root->children.end(); it++)
  {
    set.push_back(it->first);
    printtries_dfs(it->second, set, result);
    set.pop_back();
  }
}
vector<string> printtries(tries1 *tries_root)
{
  vector<string>result;
  string set;
  printtries_dfs(tries_root, set, result);
  return result; 
}

int deletetries_helper(tries1 *tries_root, int index, string word)
{
  if (tries_root == NULL || tries_root->children.find(word[index]) == tries_root->children.end())
  {
    return 0;
  }
  if ( index == word.size()-1)
  {
    if (1 == isleafnode(tries_root->children[word[index]]) )
    {
      tries_root->children[word[index]]->count = 0;
      if (1 == isTerminateNode(tries_root->children[word[index]]))
      {
        tries_root->children.erase(word[index]);
      }
      return 1;
    }
    else
    {  
      return 0;
    }
  }
  else
  {
    if ( 1 == deletetries_helper(tries_root->children[word[index]], index+1, word))
    {
      if (1 == isTerminateNode(tries_root->children[word[index]]) &&  0 == isleafnode(tries_root->children[word[index]]) )
      {
        tries_root->children.erase(word[index]);
     }
     return 1;
  }
  return 0;
 }
}

int deletetries(tries1 *tries_root, string word)
{
  int ret = deletetries_helper(tries_root, 0, word);
  return ret;
}
void test_tries()
{
 tries1 *root = createTries();
 insertTries(root, "string");
 insertTries(root, "stringstream");
 insertTries(root, "word");
 insertTries(root, "wordwide");
 int ret = searchTries(root, "str");
 ret = searchTries(root, "word");
 vector<string> retstr =  printtries(root);
 //int isdelete = deletetries(root, "string");
 //int isdelete = deletetries(root, "stringstream");
 int isdelete = deletetries(root, "stringstrea");
 vector<string> retstr_delete =  printtries(root);
}







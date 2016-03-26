//
//
//Design a data structure that supports the following two operations: 
//void addWord(word)
//bool search(word)
//
//
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//For example:
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//
//
class trienode
{
public:    
    unordered_map<char, class trienode*>children;
    int isWord;
    
    trienode()
    {
        isWord = 0;
    }
};

class WordDictionary 
{
    trienode *root;
    
public:
    WordDictionary()
    {
        root = new trienode;
    }

    // Adds a word into the data structure.
    void addWord(string word) 
    {
        trienode *node = root;
        for ( int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if ( node->children.find(c) == node->children.end())
            {
                node->children[c] = new trienode;
            }
            node = node->children[c];
        }
        node->isWord = 1;
    }
    
    int find(string word, int index, trienode *node)
    {
        if ( index == word.length())
        {
            return 0;
        }
        
        char c = word[index];
        if ( node->children.find(c) != node->children.end())
        {
            if (index == word.length()-1 && node->children[c]->isWord == 1)
            {
                return 1;
            }
            return find(word, index+1, node->children[c]);
        }
        else if (c == '.')
        {
            int result = 0;
            unordered_map<char, trienode*>::iterator it;
            
            for( it = node->children.begin(); it != node->children.end(); it++)
            {
                if ( index == word.length()-1 && it->second->isWord == 1)
                {
                    return 1;
                }
                
                if ( 1 == find(word, index+1, it->second))
                {
                    result = 1;
                }
            }
            return result;
        }
        else
        {
            return 0;
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        trienode *node = root;
        return find(word, 0, node);
        
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

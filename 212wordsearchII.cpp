//
//
//Given a 2D board and a list of words from the dictionary, find all words in the board. 
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word. 
//
//For example,
// Given words = ["oath","pea","eat","rain"] and board = 
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
//  ]
//
// Return ["eat","oath"]. 
//
int findchar(vector<string>words, int index, char c)
{
    for (int i = 0; i < words.size(); i++)
    {
        if ( index < words[i].size() && words[i][index] == c )
        {
            return 1;
        }
    }
    return 0;
}

// better but still TLE 

void wordSearchII_helper2(vector<vector<char> > &board, unordered_set<string>&hash_set, 
                string &subset, vector<string>&result, vector<vector<int>>&isVisited, 
                int x, int y, int max_wordLen, int index, vector<string> &words)
{
    
    if ( index >= max_wordLen || 0 == findchar(words, index, board[x][y]))
    {
        return;
    }
   
    subset.push_back(board[x][y]);
    isVisited[x][y] = 1;
    
    if ( hash_set.find(subset) != hash_set.end())
    {
        hash_set.erase(subset);
        result.push_back(subset);
    }
 
    int n = board.size();
    int m = board[0].size();


    if ( x+1 < n && isVisited[x+1][y] == 0)
    {
        wordSearchII_helper2(board, hash_set, subset, result, isVisited, x+1, y, max_wordLen, index+1, words);
    }
    
    if ( x-1 >= 0 && isVisited[x-1][y] == 0)
    {
        wordSearchII_helper2(board, hash_set, subset, result, isVisited, x-1, y, max_wordLen, index+1, words);
    }
    
    if ( y-1 >= 0 && isVisited[x][y-1] == 0)
    {
        wordSearchII_helper2(board, hash_set, subset, result, isVisited, x, y-1, max_wordLen, index+1, words);
    }

    if ( y+1 < m && isVisited[x][y+1] == 0)
    {
        wordSearchII_helper2(board, hash_set, subset, result, isVisited, x, y+1, max_wordLen, index+1, words);
    }
    
    subset.pop_back();
    isVisited[x][y] = 0;

}

int max(int a, int b)
{
    return ( a> b)?a:b;
}

vector<string> findWords2(vector<vector<char>>& board, vector<string>& words) 
{
    
    vector<string>result;
    if ( 0 == board.size() || 0 == board[0].size())
    {
        return result;
    }
        
    unordered_set<string>hash_set;
    int max_wordLen = 0;
    for ( int i = 0; i < words.size(); i++)
    {
        hash_set.insert(words[i]);
        max_wordLen = max(max_wordLen, words[i].size());
    }
        
    int n = board.size();
    int m = board[0].size();
        
    for ( int i = 0; i < n; i++)
    {
        for ( int j = 0; j < m; j++)
        {
            vector<vector<int>>isVisited(n, vector<int>(m, 0));
            string subset;
                
            //wordSearchII_helper1(board, hash_set, subset, result, isVisited, i, j, max_wordLen);   
            wordSearchII_helper2(board, hash_set, subset, result, isVisited, i, j, max_wordLen, 0, words);
        }
    }
    
    return result;
}

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") 
        {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie 
    {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) 
        {
            TrieNode *p = root;
            for (auto &a : s) 
            {
                int i = a - 'a';
                if (!p->child[i]) 
                {
                    p->child[i] = new TrieNode();
                }
                p = p->child[i];
            }
            p->str = s;
        }
    };
    void search(vector<vector<char> > &board, TrieNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res) 
    { 
        if (!p->str.empty()) 
        {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) 
        {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) 
            {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.insert(a);
        for (int i = 0; i < board.size(); ++i) 
        {
            for (int j = 0; j < board[i].size(); ++j) 
            {
                if (T.root->child[board[i][j] - 'a']) 
                {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
};

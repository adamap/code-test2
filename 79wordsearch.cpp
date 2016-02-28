//Given a 2D board and a word, find if the word exists in the grid. 
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once. 
//
//For example,
// Given board = 
//   [
//      ['A','B','C','E'],
//      ['S','F','C','S'],
//      ['A','D','E','E']
//   ]
//
//       word = "ABCCED", -> returns true,
//       word = "SEE", -> returns true,
//       word = "ABCB", -> returns false.
//   



int exist_helper(vector<vector<char>>& board, vector<vector<int>>&isvisited, string word, int index, int x, int y)
{
    
    if (board[x][y] != word[index]) 
    {
        return 0;
    }
    if (index == word.size()-1 )
    {
        return 1;
    }

    isvisited[x][y] = 1;
    
    if (x > 0 && isvisited[x-1][y] == 0 && exist_helper(board, isvisited, word, index+1, x-1, y))
    {
        return 1;
    }
    
    if (x < board.size()-1 && isvisited[x+1][y] == 0 && exist_helper(board, isvisited, word, index+1, x+1, y))
    {
        return 1;
    }
    
    if (y > 0 && isvisited[x][y-1] == 0 && exist_helper(board, isvisited, word, index+1, x, y-1))
    {
        return 1;
    }
    
    if (y < board[0].size()-1 && isvisited[x][y+1] == 0 && exist_helper(board, isvisited, word, index+1, x, y+1))
    {
        return 1;
    }
    
    // do this to clear isvisited record
    isvisited[x][y] = 0;

    return 0;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if ( 0 == board.size() || 0 == board[0].size())
        {
            return 0;
        }
        int m = board.size(), n = board[0].size();
        
        vector<vector<int>>isvisited(m, vector<int>(n, 0));  
        for ( int i = 0; i < board.size(); i++)
        {
            for ( int j = 0; j < board[0].size(); j++)
            {
                
                if (exist_helper(board, isvisited, word, 0, i, j) == 1 )
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

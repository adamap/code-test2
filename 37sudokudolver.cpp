


vector<int> validnumber(vector<vector<char>>&board, int row, int col)
{
    vector<int>val(9, 0);
    
    for ( int i = 0; i < 9; i++)
    {
        if ( board[row][i] != '.')
        {
            val[board[row][i]-'1'] = 1;
        }
        if ( board[i][col] != '.')
        {
            val[board[i][col]-'1'] = 1;
        }
    }

    for ( int i = row/3*3; i < row/3*3+3; i++)
    {
        for ( int j = col/3*3; j < col/3*3+3; j++)
        {
            if ( board[i][j] != '.')
            {
                val[board[i][j]-'1'] = 1;
            }
        }
    }
    
    vector<int>set;
    
    for ( int i = 0; i < 9; i++)
    {
        if ( val[i] == 0)
        {
            set.push_back(i);
        }
    }
    
    return set;
    
}

int getnextavailpos(vector<vector<char>>&board, int &row, int &col)
{
    while (row <= 8 && col <= 8)   
   {
     if (board[row][col] == '.')
     {
       return 1;
     }
     row = (col == 8) ? row + 1 : row;
     col = (col == 8) ? 0 : col + 1;
   }   
   return 0;
  
}

int solveSudoku_helper(vector<vector<char>>&board, int row, int col )
{
    int ret = getnextavailpos(board, row, col);
    if ( ret == 0)
    {
        return 1;
    }
    
    vector<int> set = validnumber(board, row, col);
    if ( set.size() == 0)
    {
        return 0;
    }
    
    for ( int i = 0; i < set.size(); i++)
    {
        board[row][col] = set[i]+'1';
        if ( solveSudoku_helper(board, row, col) == 1)
        {
            return 1;
        }
        board[row][col] = '.';
    }
    return 0;
}


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        
        solveSudoku_helper(board, 0, 0);
    }
};

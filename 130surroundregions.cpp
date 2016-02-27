//
//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region. 
//
//For example,
//
//X X X X
//X O O X
//X X O X
//X O X X
//
//
//
//After running your function, the board should be: 
//X X X X
//X X X X
//X X X X
//X O X X
//




// correct dfs, however failed at stack overflow to causing run time error

void solve_fill_helper1(vector<vector<char>>& board, int x, int y)
{
    board[x][y] = 'd';
    
    if ( x > 0 && board[x-1][y] == 'O')
    {
        solve_fill_helper1(board, x-1, y);
    }
    
    if ( x+1 < board.size() && board[x+1][y] == 'O')
    {
        solve_fill_helper1(board, x+1, y);
    }

    if ( y > 0 && board[x][y-1] == 'O')
    {
        solve_fill_helper1(board, x, y-1);
    }
    
    if ( y+1 < board[0].size() && board[x][y+1] == 'O')
    {
        solve_fill_helper1(board, x, y+1);
    }
}

// use BFS instead to avoid stack overflow
void solve_fill_helper2(vector<vector<char>>& board, int i, int j)
{
    stack<pair<int, int>>stk;
    stk.push(make_pair(i, j));
 
    while(!stk.empty())
    {
        int x =stk.top().first;
        int y =stk.top().second;
        stk.pop();
        
        board[x][y] = 'd';
        
        if ( x > 0 && board[x-1][y] == 'O')
        {
            stk.push(make_pair(x-1, y));
        }
    
        if ( x+1 < board.size() && board[x+1][y] == 'O')
        {
            stk.push(make_pair(x+1, y));
        }

        if ( y > 0 && board[x][y-1] == 'O')
        {
            stk.push(make_pair(x, y-1));
        }
    
        if ( y+1 < board[0].size() && board[x][y+1] == 'O')
        {
            stk.push(make_pair(x, y+1));
        }
    }
}


class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        if (0 == board.size() || 0 == board[0].size())
        {
            return;
        }
        
        int n = board.size(), m = board[0].size();
        for ( int i = 0; i < n; i++)
        {
            if ( board[i][0] == 'O')
            {
                solve_fill_helper2(board, i, 0);
            }
            if ( board[i][m-1] == 'O')
            {
                solve_fill_helper2(board, i, m-1);
            }
        }
        for ( int i = 0; i < m; i++)
        {
            if ( board[0][i] == 'O')
            {
                solve_fill_helper2(board, 0, i);
            }
            if ( board[n-1][i] == 'O')
            {
                solve_fill_helper2(board, n-1, i);
            }
        }
        for ( int i = 0; i < n; i++)
        {
            for ( int j = 0; j < m; j++)
            {
                if ( board[i][j] != 'd')
                {
                    board[i][j] = 'X';
                }
                else
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

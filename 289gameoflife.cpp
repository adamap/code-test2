//
//
//According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970." 
//
//Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article): 
//
//
//1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.
//2.Any live cell with two or three live neighbors lives on to the next generation.
//3.Any live cell with more than three live neighbors dies, as if by over-population..
//4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//
//
//Write a function to compute the next state (after one update) of the board given its current state.
//
//Follow up: 
//
//1.Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
//2.In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
//

// state 0: dead cell to dead cell
// state 1: live cell to live cell
// state 2: live cell to dead cell
// state 3: dead cell to live cell

// live cell, neighboring cell: < 2 live cells, ---> dead cell  state 2
//                              2-3 live cells, ---> live cell  state 1
//                              > 3 live cells, ---> dead cell  state 2

// dead cell, neighboring cell:   3 live cells, ---> live cell  state 3

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        if ( 0 == board.size() || 0 == board[0].size())
        {
            return;
        }
        
        int m = board.size(), n = board[0].size();
        int x_inc[] = {-1, -1, -1, 0, 1, 1,  1,  0};
        int y_inc[] = {-1,  0,  1, 1, 1, 0, -1, -1};
        
        for ( int i = 0; i < m; i++)
        {
            for ( int j = 0; j < n; j++)
            {
                int count = 0;
                for ( int k = 0; k < 8; k++)
                {
                    int x = i + x_inc[k];
                    int y = j + y_inc[k];
                    
                    if ( x >= 0 && x < m && y >= 0 && y < n)
                    {
                        if ( board[x][y] == 1 || board[x][y] == 2)
                        {
                            count ++;
                        }
                    }
                }
                
                if ( board[i][j] == 1 && (count < 2 || count > 3))
                {
                    board[i][j] = 2;
                }
                else if (board[i][j] == 0 && count  == 3)
                {
                    board[i][j] = 3;
                }
            }
        }
        
        for ( int i = 0; i < m; i++)
        {
            for ( int j = 0; j < n; j++)
            {
                board[i][j] %= 2;
            }
        }
    }
};

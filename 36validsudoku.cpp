//
//
//
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for ( int i = 0; i < 9; i++)
        {
            vector<int> nums(9, 1);
            for ( int j = 0; j < 9; j++)
            {
                if ( board[i][j] != '.' && nums[board[i][j]-'1'] == 1)
                {
                    nums[board[i][j]-'1'] = 0;
                }
                else if (board[i][j] != '.')
                {
                    return 0;
                }
            }
        }
        
        for ( int i = 0; i < 9; i++)
        {
            vector<int> nums(9, 1);
            for ( int j = 0; j < 9; j++)
            {
                if ( board[j][i] != '.' && nums[board[j][i]-'1'] == 1)
                {
                    nums[board[j][i]-'1'] = 0;
                }
                else if (board[j][i] != '.')
                {
                    return 0;
                }
            }
        }
        
        for ( int i = 0; i < 9; i++)
        {
            vector<int> nums(9, 1);
            for ( int j = 0; j < 9; j++)
            {
                int index1 = i/3*3+j/3;
                int index2 = i%3*3+j%3;
                
                if ( board[index1][index2] != '.' && nums[board[index1][index2]-'1'] == 1)
                {
                    nums[board[index1][index2]-'1'] = 0;
                }
                else if (board[index1][index2] != '.')
                {
                    return 0;
                }
            }
        }    
        return 1;
    }
};

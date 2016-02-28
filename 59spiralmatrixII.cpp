//
//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
// Given n = 3, 
// You should return the following matrix: [
//    [ 1, 2, 3 ],
//    [ 8, 9, 4 ],
//    [ 7, 6, 5 ]
//    ]
//
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        
        int row_start = 0, row_end= n-1, col_start = 0, col_end = n-1;
        
        int index = 1;
        int i, j;
        while(row_start <= row_end )
        {
            if ( row_start == row_end)
            {
                matrix[row_start][row_end]  = index;
                break;
            }
            
            for ( i = col_start; i < col_end; i++)
            {
                matrix[row_start][i] = index++;
            }
            
            for ( j = row_start; j < row_end; j++)
            {
                matrix[j][i] = index++;
            }
            
            for ( i = col_end; i > col_start; i--)
            {
                matrix[j][i] = index++;
            }

            for ( j = row_end; j > row_start; j--)
            {
                matrix[j][i] = index++;
            }
            
            row_start++;
            row_end--;
            col_start++;
            col_end--;
        }
        
        return matrix;
    }
};

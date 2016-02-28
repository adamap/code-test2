//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order. 
//
//For example,
// Given the following matrix: 
// [
//   [ 1, 2, 3 ],
//   [ 4, 5, 6 ],
//   [ 7, 8, 9 ]
//  ]
//
//
//    You should return [1,2,3,6,9,8,7,4,5]



vector<int> spiralOrder_iterative(vector<vector<int>>& matrix)
{
    vector<int>result;
    if ( 0 == matrix.size() || 0 == matrix[0].size())
    {
        return result;
    }
        
    int row_start = 0, col_start = 0;
    int row_end = matrix.size()-1, col_end = matrix[0].size()-1;
    int index = 0;
    result.resize((row_end+1)*(col_end+1), 0);
        
    while(row_start <= row_end && col_start <= col_end )
    {
        if ( row_start == row_end)
        {
            for (int i = col_start; i <= col_end; i++)
            {
                result[index++] = matrix[row_start][i];
            }
            break;
        }
            
        if ( col_start == col_end)
        {
             for (int i = row_start; i <= row_end; i++)
            {
                result[index++] = matrix[i][col_end];
            }
            break;
        }
            
        for (int i = col_start; i < col_end; i++)
        {
            result[index++] = matrix[row_start][i];
        }
            
        for (int i = row_start; i < row_end; i++)
        {
            result[index++] = matrix[i][col_end];
        }
            
        for (int i = col_end; i > col_start; i--)
        {
            result[index++] = matrix[row_end][i];
        }
            
        for (int i = row_end; i > row_start; i--)
        {
            result[index++] = matrix[i][col_start];
        }
            
        row_start++;
        row_end--;
        col_start++;
        col_end--;
    }
    return result;
}

void spiralOrder_recursive(vector<vector<int>>& matrix, vector<int>&result, int index, int m, int n)
{
    if (result.size() == matrix.size()*matrix[0].size())
    {
        return;
    }
    
    if ( m == 1)
    {
        for ( int i = 0; i < n; i++)
        {
            result.push_back(matrix[index][index+i]);
        }
        return;
    }
    
    if ( n == 1)
    {
        for ( int i = 0; i < m; i++)
        {
            result.push_back(matrix[index+i][index]);
        }
        return;
    }
    
    int i, j;
    for ( i = 0; i < n-1; i++)
    {
        result.push_back(matrix[index][index+i]);
    }
    
    for ( j = 0; j < m-1; j++)
    {
        result.push_back(matrix[index+j][index+i]);
    }
    
    for ( ; i > 0; i--)
    {
        result.push_back(matrix[index+j][index+i]);
    }

    for ( ; j > 0; j--)
    {
        result.push_back(matrix[index+j][index+i]);
    }
    
    spiralOrder_recursive(matrix, result, index+1, m-2, n-2);
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        //return spiralOrder_iterative(matrix);
        vector<int>result;
        if ( 0 == matrix.size() || 0 == matrix[0].size())
        {
            return result;
        }
        int m = matrix.size(), n = matrix[0].size();
        
        spiralOrder_recursive(matrix, result, 0, m, n);
    }
};


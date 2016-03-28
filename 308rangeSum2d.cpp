//
//
//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//
//Range Sum Query 2D
//The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8. 
//
//Example:
//
//Given matrix = [
//  [3, 0, 1, 4, 2],
//  [5, 6, 3, 2, 1],
//  [1, 2, 0, 1, 5],
//  [4, 1, 0, 1, 7],
//  [1, 0, 3, 0, 5]
//  ]
//
//  sumRegion(2, 1, 4, 3) -> 8
//  update(3, 2, 2)
//  sumRegion(2, 1, 4, 3) -> 10
//
//
//
//  Note:
//
//  1.The matrix is only modifiable by the update function.
//  2.You may assume the number of calls to update and sumRegion function is distributed evenly.
//  3.You may assume that row1 ¡ row2 and col1 ¡ col2.
//
//
//2d binary index tree

class NumMatrix {

vector<vector<int>> mat;
vector<vector<int>> bit;

public:
    NumMatrix(vector<vector<int>> &matrix) 
    {
        if (0 == matrix.size() || 0 == matrix[0].size() )
        {
            return;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        mat.resize(n+1, vector<int>(m+1, 0));
        bit.resize(n+1, vector<int>(m+1, 0));
        
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = 0; j < matrix[i].size(); ++j) 
            {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) 
    {
        int diff = val - mat[row + 1][col + 1];
        
        for (int i = row + 1; i < mat.size(); i += i&-i) 
        {
            for (int j = col + 1; j < mat[i].size(); j += j&-j) 
            {
                bit[i][j] += diff;
            }
        }
        
        mat[row + 1][col + 1] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
    }
    
    int getSum(int row, int col) 
    {
        int res = 0;
        for (int i = row; i > 0; i -= i&-i) 
        {
            for (int j = col; j > 0; j -= j&-j) 
            {
                res += bit[i][j];
            }
        }
        return res;
    } 

};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);

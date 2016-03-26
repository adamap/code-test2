//
//
//Given two sparse matrices A and B, return the result of AB.
//
//You may assume that A's column number is equal to B's row number.
//
//Example:
//A = [
//  [ 1, 0, 0],
//    [-1, 0, 3]
//    ]
//
//    B = [
//      [ 7, 0, 0 ],
//        [ 0, 0, 0 ],
//        [ 0, 0, 1 ]
//       ]
//
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
//
//

vector<vector<int>> multiply_n3(vector<vector<int>>& A, vector<vector<int>>& B) 
{
    int n = A.size();
    int m = B[0].size();
        
    vector<vector<int>> result(n, vector<int>(m, 0));
        
    int l = A[0].size();
        
    for ( int i = 0; i < n; i++)
    {
        for ( int j = 0; j < m; j++)
        {
            for ( int k = 0; k < l; k++)
            {
                result[i][j] += A[i][k]*B[k][j];
            }
        }
    }
        
    return result;
}

vector<vector<int>> multiply_opt(vector<vector<int>>& A, vector<vector<int>>& B) 
{
    int n = A.size();
    int m = B[0].size();
        
    vector<vector<int>> result(n, vector<int>(m, 0));
        
    int l = A[0].size();
        
    for ( int i = 0; i < n; i++)
    {
        for ( int k = 0; k < l; k++)
        {
            if (A[i][k] == 0)
            {
                continue;
            }
            
            for ( int j = 0; j < m; j++)
            {
                result[i][j] += A[i][k]*B[k][j];
            }
        }
    }
        
    return result;
}

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        //return multiply_n3(A, B);
        return multiply_opt(A, B);
    }
};

//
//
//
//Given an integer matrix, find the length of the longest increasing path.
//
//From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
//Example 1: 
//nums = [
//  [9,9,4],
//  [6,6,8],
//  [2,1,1]
//  ]
//
//
//
//      Return 4
//       The longest increasing path is [1, 2, 6, 9].
//
//       Example 2: 
//       nums = [
//       [3,4,5],
//       [3,2,6],
//       [2,2,1]
//          ]
//
//
//
//       Return 4
//         The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//


int longestIncreasingPath_dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int> >&dp )
{
    int n = matrix.size(), m = matrix[0].size();
    
    if ( dp[x][y] != 0 )
    {
        return dp[x][y];
    }

    int max_len = 1;
    if (x > 0 && matrix[x-1][y] > matrix[x][y] )
    {
        max_len = max(max_len, 1+longestIncreasingPath_dfs(matrix, x-1, y,  dp));
    }
    if (x < n-1 && matrix[x+1][y] > matrix[x][y] )
    {
        max_len = max(max_len, 1+longestIncreasingPath_dfs(matrix, x+1, y,  dp));
    }
    if (y > 0 && matrix[x][y-1] > matrix[x][y] )
    {
        max_len = max(max_len, 1+longestIncreasingPath_dfs(matrix, x, y-1,  dp));
    }
    if (y < m-1 && matrix[x][y+1] > matrix[x][y] )
    {
        max_len = max(max_len, 1+longestIncreasingPath_dfs(matrix, x, y+1,  dp));
    }
    
    dp[x][y] = max_len;

    return max_len;
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if ( 0 == matrix.size() || 0 == matrix[0].size())
        {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        
        int result = INT_MIN;
        for ( int i = 0; i < n; i++)
        {
            for ( int j = 0; j < m; j++)
            {
                int max_len = longestIncreasingPath_dfs(matrix, i, j, dp);
                result = max(result, max_len);
            }
        }
        
        return result;
    }
};

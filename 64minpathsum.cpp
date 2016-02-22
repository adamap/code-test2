//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//


// recursion , time limti exceeded, pratice 

void minPathSum_helper(vector<vector<int>>grid, int x, int y, int sum, int &minsum)
{
    int n = grid.size(), m = grid[0].size();
    
    if ( x == n-1 && y == m-1)
    {
        minsum = min(sum, minsum);
        return;
    }
    
    if ( x+1 < n )
    {
        minPathSum_helper(grid, x+1, y, sum+grid[x+1][y], minsum);
    }
    
    if ( y+1 < m )
    {
        minPathSum_helper(grid, x, y+1, sum+grid[x][y+1], minsum);
    }
}

int minpathsum_dp(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];
    for ( int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0]+grid[i][0];
    }
    
    for ( int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }

    for ( int i = 1; i < n; i++)
    {
        for ( int j = 1; j < m; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[n-1][m-1];
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if (0 == grid.size() || 0 == grid[0].size())
        {
            return 0;
        }
        //int sum = grid[0][0];
        //int minsum = INT_MAX;
        //minPathSum_helper(grid, 0, 0, sum, minsum);
        //return minsum;
        return minpathsum_dp(grid);
    }
};

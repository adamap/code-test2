//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//
//
//There is one obstacle in the middle of a 3x3 grid as illustrated below.


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if ( 0 == obstacleGrid.size() || 0 == obstacleGrid[0].size() )
        {
            return 0;
        }
        
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for ( int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0 )
            {
                dp[i][0] = dp[i-1][0];
            }
            else
            {
                dp[i][0] = 0;
            }
        }
        
        for ( int i = 1; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0 )
            {
                dp[0][i] = dp[0][i-1];
            }
            else
            {
                dp[0][i] = 0;
            }
        }
        
        for ( int i = 1; i < m; i++)
        {
            for ( int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};

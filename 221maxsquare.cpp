//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area. 
//
//For example, given the following matrix: 
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Return 4. 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if ( 0 == matrix.size() || 0 == matrix[0].size())
        {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int max_square = 0;
        for ( int i = 1; i <= n; i++)
        {
            for ( int j = 1; j <= m; j++)
            {
                if ( matrix[i-1][j-1] == '0')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1])+1;
                }
                max_square = max(max_square, dp[i][j]*dp[i][j]);
            }
        }
        
        return max_square;
    }
};

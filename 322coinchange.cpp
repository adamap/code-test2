//
//
//You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. 
//
//Example 1:
// coins = [1, 2, 5], amount = 11
//  return 3 (11 = 5 + 5 + 1) 
//
//  Example 2:
//   coins = [2], amount = 3
//    return -1. 
//
//    Note:
//     You may assume that you have an infinite number of each kind of coin. 
//
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
/*        if ( amount == 0 || 0 == coins.size())
        {
            return 0;
        }
        int n = coins.size();
        vector<vector<int> >dp(n + 1, vector<int>(amount + 1, INT_MAX));
        
        for ( int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= amount; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                dp[i][j] = dp[i - 1][j];
                
                for (int k = 1; k*coins[i-1] <= j; k++)
                {
                    if ( dp[i - 1][j-k*coins[i-1]] != INT_MAX)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j-k*coins[i-1]]+k);
                    }
                }
            }
        }
       
        if (dp[n][amount] != INT_MAX)
        {
            return dp[n][amount];
        }
        
        return -1;
        */
        
        if ( amount == 0 || 0 == coins.size())
        {
            return 0;
        }
        
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int n = coins.size();
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = coins[i]; j <= amount; ++j) 
            {
                if (dp[j-coins[i]] != INT_MAX) 
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

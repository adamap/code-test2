//
//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
//Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        
        if ( n <= 1)
        {
            return 0;
        }
        
        if ( k >= n/2)
        {
            int profit = 0;
            for ( int i = 1; i < n; i++)
            {
                if ( prices[i] > prices[i-1])
                {
                    profit += prices[i]-prices[i-1];
                }
            }
            return profit;
        }
        
        vector<vector<int>>globalmax(n+1, vector<int>(k+1, 0));
        vector<vector<int>>localmax(n+1, vector<int>(k+1, 0));
        
        for ( int i = 2; i <= n; i++)
        {
            int diff = prices[i-1] - prices[i-2];
            for ( int j = 1; j <= k; j++)
            {
                localmax[i][j]  = max(globalmax[i-1][j-1]+diff, localmax[i-1][j]+diff);
                globalmax[i][j] = max(globalmax[i-1][j], localmax[i][j]);
            }
        } 
        return globalmax[n][k];
    }
};

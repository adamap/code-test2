//
//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//
//Example:
//
//prices = [1, 2, 3, 0, 2]
//maxProfit = 3
//transactions = [buy, sell, cooldown, buy, sell]
//
//
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (0 == prices.size())
        {
            return 0;
        }
        int n = prices.size();
        
        // sell at ith day
        vector<int>sellDP(n, 0);
        
        // buy in at ith day
        vector<int>buyDP(n, 0);
        
        buyDP[0] = -prices[0];
        sellDP[0] = 0;
        
        for ( int i = 1; i < n; i++)
        {
            sellDP[i] = max(sellDP[i-1], buyDP[i-1]+prices[i]);
            
            if ( i >= 2)
            {
                buyDP[i] = max(buyDP[i-1], sellDP[i-2]-prices[i]);
            }
            else
            {
                buyDP[i] = max(buyDP[i-1], -prices[i]);
            }
        }
        
        return sellDP[n-1];
        
    }
};

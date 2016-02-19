//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
//Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        if (0 == n)
        {
            return 0;
        }
        
        vector<int> max_profit_left(n, 0);
        int min = INT_MAX;
        int max_profit = 0;
        
        for ( int i = 0; i < n; i++)
        {
            if ( min > prices[i])
            {
                min = prices[i];
            }
            else
            {
                max_profit = max(max_profit, prices[i] - min);
            }
            max_profit_left[i] = max_profit;
        }
     
        vector<int> max_profit_right(n, 0);
        int max_temp = INT_MIN;
        max_profit = 0;
        for ( int i = n-1; i >= 0; i--)
        {
            if ( max_temp < prices[i])
            {
                max_temp = prices[i];
            }
            else
            {
                max_profit = max(max_profit, max_temp - prices[i]);
            }
            max_profit_right[i] = max_profit;
        }
        int max_total = 0;
        for ( int i = 0; i < n; i++)
        {
            max_total = max(max_total, max_profit_left[i]+max_profit_right[i]);        
        }
        
        return max_total;
    }
};

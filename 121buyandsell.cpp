//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if ( 0 == prices.size())
        {
            return 0;
        }
        
        int maxprofit = 0;
        int min = INT_MAX;
        
        for ( int i = 0; i < prices.size(); i++)
        {
            if ( min > prices[i])
            {
                min = prices[i];
            }
            else
            {
                maxprofit = max(maxprofit, prices[i] - min);
            }
        }
        
        return maxprofit;
    }
};

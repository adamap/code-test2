//
//
//
//There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color. 
//
//The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses. 
//
//Note:
// All costs are positive integers.
//
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) 
    {
         // 0 house to paint and 0 cost
        if (0 == costs.size())
        {
            return 0;
        }
        int len = costs.size();
 
        int prevMin = 0, prevSecMin = 0, prevMinColorIdx = -1;
        for (int i = 0; i < len; i++)
        {
            int currMin = INT_MAX, currSecMin = INT_MAX, currMinColorIdx = -1;
            for (int j = 0; j < costs[i].size(); j++)
            {
                costs[i][j] = costs[i][j] + ((prevMinColorIdx == j) ? prevSecMin : prevMin);
                if (costs[i][j] < currMin)
                {
                    currSecMin = currMin;
                    currMin = costs[i][j];
                    currMinColorIdx = j;
                }
                else if (costs[i][j] < currSecMin)
                {
                    currSecMin = costs[i][j];
                }
            }
            prevMin = currMin;
            prevSecMin = currSecMin;
            prevMinColorIdx = currMinColorIdx;
        }
        return prevMin;
        
    }
};

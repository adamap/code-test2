//
//
//There is a fence with n posts, each post can be painted with one of the k colors.
//
//You have to paint all the posts such that no more than two adjacent fence posts have the same color. 
//
//Return the total number of ways you can paint the fence. 
//
class Solution {
public:
    int numWays(int n, int k) 
    {
        if (n <= 1 || k == 0)
        {
            return k*n;
        }
 
        int noways_1 = k, noways_2 = k*(k - 1);
        
        for (int i = 3; i <= n; i++)
        {
            int noways_3 = (k - 1)*(noways_1 + noways_2);
            noways_1 = noways_2;
            noways_2 = noways_3;
        }
        
        return (noways_1 + noways_2);
        
    }
};

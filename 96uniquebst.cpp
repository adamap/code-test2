

//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
// Given n = 3, there are a total of 5 unique BST's. 
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//      /     /       \                 \
//     2     1         2                 3
//
//   

// recursion + memorization
int numTrees_rec(int n)
{
    if ( n <= 1)
    {
        return 1;
    }
        
    int result = 0;
    vector<int>record(n, -1);
        
    for ( int i = 0; i < n; i++)
    {
        int num_i;
        if (record[i] != -1 )
        {
            num_i = record[i];
        }
        else
        {
            num_i = numTrees_rec(i);
            record[i] = num_i;
        }
        int num_j;
        if (record[n-i-1] != -1 )
        {
            num_j = record[n-i-1];
        }
        else
        {
            num_j = numTrees_rec(n-i-1);    
            record[n-i-1] = num_j;
        }

        result += num_i*num_j;
            
    }
    return result; 
}

int numTrees_dp(int n)
{
    
    vector<int>dp(n+1, 0);
    dp[0] = dp[1] = 1;
    
    for ( int i = 2; i <= n; i++)
    {
        for ( int j = 0; j < i; j++)
        {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
    
}

class Solution {
public:
    int numTrees(int n) 
    {
        return numTrees_dp(n);
    }
};                    

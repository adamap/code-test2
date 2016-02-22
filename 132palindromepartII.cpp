//Given a string s, partition s such that every substring of the partition is a palindrome. 
//
//Return the minimum cuts needed for a palindrome partitioning of s. 
//
//For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 

class Solution {
public:
    int minCut(string s) 
    {
        if (0 == s.size())
        {
            return 0;
        }
        
        vector<vector<int>>dp(s.size(), vector<int>(s.size()+1, 0));
        
        for ( int i = 0; i < s.size(); i++)
        {
            dp[i][1] = 1;
   
        }
        
        for ( int len = 2; len <= s.size(); len++)
        {
            for ( int i = 0; i <= s.size()-len; i++)
            {
                if ( len == 2)
                {
                    dp[i][len] = (s[i] == s[i+1]);
                }
                else
                {
                    dp[i][len] = (s[i] == s[i+len-1])&&dp[i+1][len-2];
                }

            }
        }
        
        vector<int>mincut(s.size(), INT_MAX);
        
        for ( int  i = 0; i < s.size(); i++)
        {
            if ( dp[0][i+1] == 1)
            {
                mincut[i] = 0; 
            }
            else
            {
                for ( int j = 0; j < i; j++)
                {
                    if ( mincut[j] != INT_MAX && dp[j+1][i-j] == 1 )
                    {
                        mincut[i] = min(mincut[i], mincut[j]+1);
                    }
                }
            }
        }
        
        return mincut[s.size()-1];

    }
};


//
//
//
//Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"]. 
//
//Return true because "leetcode" can be segmented as "leet code". 
//


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) 
    {
        int n = s.size();
        
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        
        for ( int i = 1; i <= n; i++)
        {
            for ( int j = 0; j < i; j++)
            {
                if ( dp[j] == 1 && wordDict.find(s.substr(j, i-j)) != wordDict.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

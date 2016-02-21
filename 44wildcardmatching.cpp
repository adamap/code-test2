//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") ¡ false
//isMatch("aa","aa") ¡ true
//isMatch("aaa","aa") ¡ false
//isMatch("aa", "*") ¡ true
//isMatch("aa", "a*") ¡ true
//isMatch("ab", "?*") ¡ true
//isMatch("aab", "c*a*b") ¡ false
bool isMatch_dp(string s, string p)
{
    int n = s.size();
    int m = p.size();

    vector<vector<char>>dp(n+1, vector<char>(m+1, 0));
        
    dp[0][0] = 1;
        
    for ( int i = 1; i <= m; i++)
    {
        if ( p[i-1]== '*' && dp[0][i-1] == 1)
        {
            dp[0][i] = 1;
        }
    }
        
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 1; j <= m; j++)
        {
            if ( s[i-1] == p[j-1] || p[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if (p[j-1] == '*')
            {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
    }
        
    return dp[n][m];
}

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        return  isMatch_dp( s,  p);
    }
};


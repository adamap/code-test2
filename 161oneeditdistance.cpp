//
//
//Given two strings S and T, determine if they are both one edit distance apart.
//

class Solution {
public:
    bool isOneEditDistance(string s, string t) 
    {
        if ( s.length() > t.length())
        {
            swap(s, t);
        }
        
        if ( t.length()-s.length() > 1)
        {
            return 0;
        }
        
        int found = 0;
        
        for ( int i = 0, j = 0; i < s.length(); i++, j++)
        {
            if ( s[i] != t[j])
            {
                if ( found == 1)
                {
                    return 0;
                }
                found  = 1;
                if ( s.length() < t.length())
                {
                    i--;
                }
            }
        }
        
        return (found || s.length() < t.length());
    }
};



// edit distance, for reference

int min(int a, int b)
{
return (a < b) ? a : b;
}

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) 
    {
        // write your code here
        int n = word1.size();
    int m = word2.size();

    vector<vector<int> >dp(n + 1, vector<int>(m + 1, 0));

    dp[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
    dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
    dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++)
    {
    for (int j = 1; j <= m; j++)
    {
    dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1),
   ( dp[i - 1][j - 1] + ((word1[i-1] == word2[j-1]) ? 0 : 1) ) );
    }
    }

    return dp[n][m];
    }
};


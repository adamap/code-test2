//Implement regular expression matching with support for '.' and '*'.
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
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
//isMatch("aa", "a*") ¡ true
//isMatch("aa", ".*") ¡ true
//isMatch("ab", ".*") ¡ true
//isMatch("aab", "c*a*b") ¡ true
//



// '*' meaning preceeding character+'*' can match 0,1 or more characters in s
// 0  means '*' cancel out its previous character in p
// 1 means c+'*' matches 1 character in s, for example s: "a" p: "a*"
// more characters for example s:"aaaaa" p:"a*" or p:".a"
bool isMatch_dp(string s, string p)
{
    int n = s.size(), m = p.size();
    
    // dp[i][j] i number of characters from s matches 
    // with j number of characters frame p or not
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
  
    //init process
    dp[0][0] = 1;
    
    for ( int i = 1; i <= m; i++)
    {
        if ( p[i-1] == '*')
        {
            if ( i > 1)
            {
                // in p, character+'*' can be zero out
                // so it matches with zero content of s
                dp[0][i] = dp[0][i-2];
            }
            else
            {
                dp[0][i] = 0;
            }
        }
    }
    
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 1; j <= m; j++)
        {
            char cs = s[i-1];
            char ps = p[j-1];
            
            if ( ps != '*')
            {
                if ( cs == ps || ps == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            else
            {
                if ( j > 1)
                {
                    if ( cs != p[j-2] && p[j-2] != '.')
                    {
                        //'*' matches zero precedding characters
                        dp[i][j] = dp[i][j-2];
                    }
                    else
                    {
                        //dp[i-1][j-2] '*' matches 1 preceeding character
                        //dp[i-1][j]   '*' matches many preceeding characters
                        //dp[i][j-2]   '*' matches 0 preceeding character
                        dp[i][j] = dp[i][j-2]||dp[i-1][j]||dp[i-1][j-2];                    
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    
    return dp[n][m];
}


// recursion method (time exceed limit, not sure how to optimize)
bool isMatch_rec(string s, string p)
{
    if ( p.size() == 0)
    {
      return (s.size() == 0);
    }

  if (p.size() == 1)
  {
    if (s.size() == 0 || ((s[0] != p[0]) && (p[0] != '.') ))
    {
      return 0;
    }
    return isMatch_rec(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
  }

  // already make sure p.size() >= 2 so it is safe to access p[1]
  if (p[1] != '*')
  {
    if (s.size() > 0 && (s[0] == p[0] || p[0] == '.'))
    {
      return isMatch_rec(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1)); 
    }  
    else
    {
      return 0;
    }
  }    
  else 
  {
    string p_sub; 
    if (p.size() > 2)
   {
      p_sub = p.substr(2, p.size() - 2);
   }
  // match 0, 1 or more preceeding characters
  while(s.size() > 0 && (s[0] == p[0] || p[0] == '.'))
  {
      if (1 == isMatch_rec(s, p_sub))
      {
        return 1; 
      }
      if (s.size() > 1)
      {
        s = s.substr(1, s.size() - 1);
      }
      else
      {
        s.pop_back();
      }
    }
    return isMatch_rec(s, p_sub);
  }
  return 0;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        //return isMatch_dp( s,  p);
        return isMatch_rec(s, p);
    }
};

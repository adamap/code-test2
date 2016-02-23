//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring. 
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2. 
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
//


int longestValidParentheses_stk(string s)
{
    if (0 == s.size())
    {
        return 0;
    }
        
    stack<pair<int, int>>stk;
    
    int longestlen = 0;
        
    for ( int i = 0; i < s.size(); i++)
    {
        if ( s[i] == ')')
        {
            if ( stk.empty() || stk.top().second == 0)
            {
                stk.push(make_pair(i, 0));
            }
            else
            {
                stk.pop();
                
                int index = stk.empty()?-1:stk.top().first;
                    
                longestlen = max(longestlen, i-index);    
            }
        }
        else
        {
            stk.push(make_pair(i,1));
        }
    }
        
    return longestlen;
}


int longestValidParentheses_dp(string s)
{
    if (0 == s.size())
    {
        return 0;
    }
    // dp[i] longest valid parentheses end at i-1
    int n = s.size();
    vector<int>dp(n+1, 0);
    int maxlen = 0;
    
    for ( int i = 1; i <= s.size(); i++)
    {
        int len = dp[i-1];
        int j = i - len - 2;
        
        if ( s[i-1] == '(' || j < 0 || s[j] == ')')
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i-1]+2+dp[j];
        }
        maxlen = max(maxlen, dp[i]);        
    }
    
    return maxlen;
}

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        //return longestValidParentheses_stk(s);
        return longestValidParentheses_dp(s);
    }
};

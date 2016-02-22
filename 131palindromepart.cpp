//Given a string s, partition s such that every substring of the partition is a palindrome. 
//
//Return all possible palindrome partitioning of s. 
//
//For example, given s = "aab",
// Return 
//   [
//       ["aa","b"],
//       ["a","a","b"]
//   ]
//


void partition_helper(string s, int index,  vector<vector<string>>&result, vector<vector<int>>dp, vector<string>temp_result)
{
    if ( index == s.size())
    {
        if ( temp_result.size() > 0)
        {
            result.push_back(temp_result);
        }
        return;
    }
    
    for ( int i = 1; i <= s.size(); i ++)
    {
        if ( dp[index][i] == 1)
        {
            temp_result.push_back(s.substr(index, i));
            partition_helper(s,index+i, result, dp, temp_result);
            temp_result.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        if (0 == s.size())
        {
            return result;
        }
        
        vector<vector<int>>dp(s.size(), vector<int>(s.size()+1, 0));

        vector<string>set;
        
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
        
        vector<string>temp_result;
        
        partition_helper(s, 0, result, dp, temp_result);
        
        return result;
    }
};             

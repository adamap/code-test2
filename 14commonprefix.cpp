//Write a function to find the longest common prefix string amongst an array of strings. 




string longestCommonPrefix1(vector<string>& strs) 
{
    string ret;
    if ( 0 == strs.size())
    {
        return ret;
    }
        
    int len = strs[0].size();
        
    string prefix = strs[0];
    int i = 0, j;
    while (i < len)
    {
        j = 1;
        for ( ; j < strs.size(); j++  )
        {
            if (strs[j][i] != prefix[i])
            {
                break;
            }
        }
        
        if (j == strs.size())
        {
            i++;
        }
        else
        {
            break;
        }
    }
    return prefix.substr(0, i);
}

string longestCommonPrefix2(vector<string>& strs) 
{
    string ret;
    if ( 0 == strs.size())
    {
        return ret;
    }
        
    int len = strs[0].size();
        
    string prefix = strs[0];
    
    int minlen = prefix.size();
    
    for ( int i = 1; i < strs.size(); i++)
    {
        int j = 0, k = 0, count = 0;
        while( j < prefix.size() && k < strs[i].size() && prefix[j] == strs[i][j])
        {
            j++;
            k++;
            count++;
        }
        
        if ( 0 == count)
        {
            return "";
        }
        
        minlen = min(minlen, count);
    }
    
    return prefix.substr(0, minlen);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        //return longestCommonPrefix1(strs);
        return longestCommonPrefix2(strs);
    }
};

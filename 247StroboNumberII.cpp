//
//
//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Find all strobogrammatic numbers that are of length = n. 
//
//For example,
// Given n = 2, return ["11","69","88","96"]. 
//


vector<string> findStrobogrammatic_helper(int m, int n)
{
    if(m == 0)
    {
        vector<string>ret;
        return ret;
    }
    if ( m == 1)
    {
        vector<string>ret;
        ret.push_back("0"); ret.push_back("1"); ret.push_back("8");
        return ret;
    }
    
    vector<string>result;
    
    vector<string> t = findStrobogrammatic_helper(m-2, n);
    
    if ( t.size() > 0)
    {
        for ( int i = 0; i < t.size(); i++)
        {
            if ( m < n)
            {
                result.push_back("0"+t[i]+"0");
            }
            result.push_back("1"+t[i]+"1");
            result.push_back("6"+t[i]+"9");
            result.push_back("9"+t[i]+"6");
            result.push_back("8"+t[i]+"8");
        }
    }
    else
    {
        result.push_back("11");
        result.push_back("69");
        result.push_back("96");
        result.push_back("88");
        if ( m < n)
        {
            result.push_back("00");
        }
    }
    
    return result;
}

class Solution {
public:
    vector<string> findStrobogrammatic(int n) 
    {
        return findStrobogrammatic_helper(n, n);
    }
};

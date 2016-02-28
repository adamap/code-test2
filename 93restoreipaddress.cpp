//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
// Given "25525511135", 
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
//


void restoreIpAddresses_helper(string s, int index, vector<string> ipset, vector<string> &result)
{
    if ( index == s.size())
    {
        if ( ipset.size() == 4)
        {
            string temp;
            for ( int i = 0; i < ipset.size(); i++)
            {
                temp.append(ipset[i]);
                temp.push_back('.');
            }
            temp.pop_back();
            result.push_back(temp);
        }
        
        return;
    }

    for ( int i = index; i < s.size() && i < index+3; i++)
    {
        string substr = s.substr(index, i-index+1);
        int ipaddint;
        istringstream is(substr);
        is>>ipaddint;
            
        if (ipaddint > 255 || ( substr.size() > 1 && substr[0] == '0' ))
        {
            continue;
        }
        ipset.push_back(substr);
            
        restoreIpAddresses_helper(s, i+1, ipset, result);
            
        ipset.pop_back();
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string>result;
        if (s.size() < 4 || s.size() > 12)
        {
            return result;
        }
        
        vector<string> ipset;
        
        restoreIpAddresses_helper(s, 0, ipset, result);
        
        return result;
    }
};

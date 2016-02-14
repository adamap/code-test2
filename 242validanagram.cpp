//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false. 
//
//Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
//  What if the inputs contain unicode characters? How would you adapt your solution to such case?
//
//

int isanagram1(string s, string t)
{
    if ( s.size() != t.size())
    {
        return 0;        
    }
    
    if ( s.size() == 0)
    {
        return (s.size() == t.size());
    }
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return (s == t);
}

int isanagram2(string s, string t)
{
    if ( s.size() != t.size())
    {
        return 0;        
    }
    
    if ( s.size() == 0)
    {
        return (s.size() == t.size());
    }
    
    unordered_map<char, int>s_map;

    for ( int i = 0; i < s.size(); i++)
    {
        s_map[s[i]] ++;
        s_map[t[i]] --;
    }
    
    for (unordered_map<char, int>::iterator it = s_map.begin(); it != s_map.end(); it++ )
    {
        if ( it->second != 0)
        {
            return 0;
        }
    }
    return 1;
}


class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //return isanagram1(s, t);
        return isanagram2(s, t);
    }
};

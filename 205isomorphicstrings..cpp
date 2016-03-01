//
//
//
//
//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
//For example,
// Given "egg", "add", return true.
//
// Given "foo", "bar", return false.
//
// Given "paper", "title", return true.


class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if ( s.size() != t.size())
        {
            return 0;
        }
        
        unordered_map<char, char>hash_map;
        
        for ( int i = 0; i < s.size(); i++)
        {
            if ( hash_map.find(s[i]) == hash_map.end())
            {
                hash_map[s[i]] = t[i];
            }
            else 
            {
                if (hash_map[s[i]] != t[i])
                {
                    return 0;
                }
            }
        }
        
        unordered_map<char, char>hash_map1;
        
        for ( int i = 0; i < t.size(); i++)
        {
            if ( hash_map1.find(t[i]) == hash_map1.end())
            {
                hash_map1[t[i]] = s[i];
            }
            else 
            {
                if (hash_map1[t[i]] != s[i])
                {
                    return 0;
                }
            }
        }
        
        return 1;

    }
};

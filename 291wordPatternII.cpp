//
//
//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
//
//Examples:
//
//1.pattern = "abab", str = "redblueredblue" should return true.
//2.pattern = "aaaa", str = "asdasdasdasd" should return true.
//3.pattern = "aabb", str = "xyzabcxzyabc" should return false.
//
//
//Notes:
// You may assume both pattern and str contains only lowercase letters. 
//


void wordPatternMatch_helper(string pattern, string str, int i, int j, unordered_set<string>&set, unordered_map<char, string>&hash_map, int &ret)
{
    if ( i == pattern.length() && j == str.length())
    {
        ret = 1;
        return;
    }
    
    if ( i >= pattern.length() || j >= str.length())
    {
        return;
    }
    
    char c = pattern[i];
    
    for ( int cut = 1; cut <= str.length()-j; cut++)
    {
        string substr = str.substr(j, cut);
        
        if ( hash_map.find(c) == hash_map.end() && set.find(substr) == set.end() )
        {
            hash_map[c] = substr;
            set.insert(substr);
            wordPatternMatch_helper(pattern, str, i+1, j+cut, set, hash_map, ret);
            hash_map.erase(c);
            set.erase(substr);
        }
        else if ( hash_map.find(c) != hash_map.end() && hash_map[c] == substr)
        {
            wordPatternMatch_helper(pattern, str, i+1, j+cut, set, hash_map, ret);
        }
    }
    
}

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) 
    {
        unordered_map<char, string>hash_map;
        unordered_set<string>set;
        
        int ret = 0;
        
        wordPatternMatch_helper(pattern, str, 0, 0, set, hash_map, ret);
        
        return ret;
        
    }
};

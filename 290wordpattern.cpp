
//
//
//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
//Examples:
//
//1.pattern = "abba", str = "dog cat cat dog" should return true.
//2.pattern = "abba", str = "dog cat cat fish" should return false.
//3.pattern = "aaaa", str = "dog cat cat dog" should return false.
//4.pattern = "abba", str = "dog dog dog dog" should return false.
//
//
//Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
// 
//


class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char, string>hash_table;
        
        vector<string>set;
        
        int i = 0, j= 0;
        while(i < str.size() )
        {
            string temp;
            while (str[i] != ' ' && i < str.size())
            {
                temp.push_back(str[i]);
                i++;
            }
            
            if ( temp.size() > 0)
            {
                set.push_back(temp);
            }
            i++;
        }
        
        if ( set.size() != pattern.size())
        {
            return 0;
        }
        
        for ( int i = 0; i < pattern.size(); i++)
        {
            if ( hash_table.find(pattern[i]) != hash_table.end())
            {
                if ( hash_table[pattern[i]] != set[i])
                {
                    return 0;
                }
            }
            else
            {
                unordered_map<char, string>::iterator it;
                for ( it = hash_table.begin(); it != hash_table.end(); it++)
                {
                    if ( it->second == set[i])
                    {
                        return 0;
                    }
                }
                hash_table[pattern[i]] = set[i];
            }
        }
        
        return 1;
        
    }
};

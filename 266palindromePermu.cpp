//
//
//Given a string, determine if a permutation of the string could form a palindrome.
//
//For example,
//"code" -> False, "aab" -> True, "carerac" -> True. 
//
class Solution {
public:
    bool canPermutePalindrome(string s) 
    {
        unordered_map<char, int>hash_map;
        
        for ( int i = 0; i < s.length(); i++)
        {
            hash_map[s[i]]++;
        }
        
        int count = 0;
        unordered_map<char, int>::iterator it;
        for (it = hash_map.begin(); it != hash_map.end(); it++)
        {
            if ( (it->second%2) != 0)
            {
                count ++;
            }
            if ( count >=2)
            {
                return 0;
            }
        }
        
        return 1;
    }
};

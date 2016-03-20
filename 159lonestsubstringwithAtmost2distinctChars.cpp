//
//
//
//Given a string, find the length of the longest substring T that contains at most 2 distinct characters. 
//
//For example, Given s = "eceba", 
//
//T is "ece" which its length is 3. 
//
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        unordered_map<char, int>hash_map;
        
        int left = 0; int max_len = 0;
        for ( int i = 0; i < s.length(); i++)
        {
            hash_map[s[i]]++;
            while(hash_map.size() > 2)
            {
                if ( hash_map[s[left]] > 0)
                {
                    hash_map[s[left]]--;
                }
                if ( hash_map[s[left]] == 0)
                {
                    hash_map.erase(s[left]);
                }
                left++;
            }
            max_len = max(max_len, i-left+1);
        }
        
        return max_len;
    }
};

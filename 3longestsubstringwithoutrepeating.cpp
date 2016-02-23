//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.


class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char>hash_set;
        
        int i = 0, j = 0; int len = 0;
        while ( i < s.size())
        {
            while( j < s.size() && hash_set.find(s[j]) == hash_set.end() )
            {
                hash_set.insert(s[j]);
                j++;
            }
            
            len = max(len, j-i);
            
            int temp = i;
            
            while( temp < j && s[temp] != s[j])
            {
                hash_set.erase(s[temp]);
                temp++;
            }
           
            i = temp+1;
            j++;
        }
        
        return len;
    }
};



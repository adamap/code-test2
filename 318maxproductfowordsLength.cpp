//
//
//
//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0. 
//
//Example 1:
//
//
//Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
//  The two words can be "abcw", "xtfn". 
//
//  Example 2:
//
//
//  Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//   Return 4
//    The two words can be "ab", "cd". 
//
//    Example 3:
//
//
//    Given ["a", "aa", "aaa", "aaaa"]
//     Return 0
//      No such pair of words. 
//
class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int max_len = INT_MIN;
        vector<int>dict(26, 0);
        for ( int i = 0; i < (int)words.size()-1; i++)
        {
            fill(dict.begin(), dict.end(), 0);
            for ( int k = 0; k < words[i].size(); k++)
            {
                dict[words[i][k] - 'a']++;
            }
            int word1len = words[i].size();
            
            for ( int j = i+1; j < words.size(); j++)
            {
                //put condition check here to speed up, otherwise time limit exceeded
                if (word1len*((int)words[j].size()) <= max_len )
                {
                    continue;
                }
                
                int found = 1;
                for ( int k = 0; k < words[j].size(); k++)
                {
                    if ( dict[words[j][k] - 'a'] > 0)
                    {
                        found = 0;
                        break;
                    }
                }
                
                if ( found == 0)
                {
                    continue;
                }
                
                max_len = word1len*words[j].size();
            }
        }
        
        if ( max_len == INT_MIN)
        {
            return 0;
        }
        return max_len;
    }
};

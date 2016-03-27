//
//
//
//Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome. 
//
//Example 1:
// Given words = ["bat", "tab", "cat"]
//  Return [[0, 1], [1, 0]]
//   The palindromes are ["battab", "tabbat"]
//
//
//   Example 2:
//    Given words = ["abcd", "dcba", "lls", "s", "sssll"]
//     Return [[0, 1], [1, 0], [3, 2], [2, 4]]
//    The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
//      

int isvalidPalindrome(string t) 
{
    for (int i = 0; i < t.size() / 2; ++i) 
    {
        if (t[i] != t[t.size() - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}

vector<vector<int>> palindromePairs1(vector<string>& words)
{
    vector<vector<int>> result;
    unordered_map<string, int>hash_map;
        
    for ( int i= 0; i < words.size(); i++)
    {
        // a list of unique words, no need to use vector<int>
        hash_map[words[i]] = i; 
    }
        
    for ( int i= 0; i < words.size(); i++)
    {
        // l == 0       ===> affix   abcdd "abc" is one possible affix   "abcdd"+"cba"
        // r == size-1, ===> prefix  ddabc "abc" is one possible prefix  "cba"  +"ddabc"
        int l = 0, r = 0;
        
        while(l <= r)
        {
            string t = words[i].substr(l, r-l);
        
            reverse(t.begin(), t.end());
            
            if ( hash_map.find(t) != hash_map.end())
            {
                string s = words[i].substr(l == 0 ?r:0, l==0?words[i].length()-r:l);
                if(hash_map[t] != i && isvalidPalindrome(s) == 1)
                {
                    if( l == 0)
                    {
                        result.push_back({i, hash_map[t]});
                    }
                    else
                    {
                        result.push_back({hash_map[t], i});
                    }
                }
            }
            
            if ( r < words[i].length())
            {
                r++;
            }
            else
            {
                l++;
            }
        }
    }
    return result;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        return palindromePairs1( words);
    }
};

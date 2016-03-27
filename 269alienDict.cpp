//
//
//There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language. 
//
//For example,
// Given the following words in dictionary, 
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
//  ]
//
//
//
//  The correct order is: "wertf".
//
//  Note:
//
//  1.You may assume all letters are in lowercase.
//  2.If the order is invalid, return an empty string.
//  3.There may be multiple valid order of letters, return any one of them is fine.
//
class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
        unordered_map<char, unordered_set<char>>adjlist;
        unordered_set<char> chars;
        unordered_map<char, int> in;
    
        for ( int i = 0; i < words.size(); i++)
        {
            for ( int j = 0; j < words[i].size(); j++)
            {
                chars.insert(words[i][j]);
            }
        }
    
        for ( int i = 0; i < words.size()-1; i++)
        {
            for ( int j = 0; j < min(words[i].size(), words[i+1].size()); j++)
            {
                if ( words[i][j] != words[i+1][j])
                {
                    adjlist[words[i][j]].insert(words[i+1][j]);
                    break;
                }
            }
        }
        
        unordered_map<char, unordered_set<char>>::iterator it;
        
        for (it = adjlist.begin(); it != adjlist.end(); it++)
        {
            unordered_set<char>:: iterator it_c;
            for ( it_c = it->second.begin(); it_c != it->second.end(); it_c++)
            {
                in[*it_c]++;
            }
        }
        
        unordered_set<char> :: iterator it_c;
        queue<char>q;
        string res = "";
        
        for ( it_c = chars.begin(); it_c != chars.end(); it_c++)
        {
            if(in[*it_c] == 0)
            {
                q.push(*it_c);
                res += *it_c;
            }
        }
        
        while(!q.empty())
        {
            char c = q.front();
            q.pop();
            
            for (it = adjlist.begin(); it != adjlist.end(); it++)
            {
                if(it->first == c)
                {
                    for ( it_c = it->second.begin(); it_c != it->second.end(); it_c++)
                    {
                        --in[*it_c];
                        if ( in[*it_c] == 0)
                        {
                            q.push(*it_c);
                            res += *it_c;
                        }
                    }
                }
            }
        }
        
        return (res.length() == chars.size())?res:"";
        
    }
};

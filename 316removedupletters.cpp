//
//
//Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results. 
//
//Example:
//
//
// Given "bcabc"
// Return "abc" 
//
// Given "cbacdcbc"
// Return "acdb" 
//

int findminindex(unordered_map<char, vector<int>>hash_map)
{
    int minidx = INT_MAX;
    
    unordered_map<char, vector<int>>::iterator it;
    for(it = hash_map.begin(); it != hash_map.end(); it++)
    {
        minidx = min(minidx, it->second[it->second.size()-1]);
    }
    
    return minidx;
}

string removeDuplicateLetters1(string s) 
{
    unordered_map<char, vector<int>>hash_map;
        
    for ( int i = 0; i < s.size(); i++)
    {
        hash_map[s[i]].push_back(i);
    }
        
    int minindex = findminindex(hash_map);
    int start = 0;
        
    string result;
    while(!hash_map.empty())
    {
        unsigned char c = 255;
        int index;
        for ( int i = start; i <= minindex; i++)
        {
            if ( s[i] < c && hash_map.find(s[i]) != hash_map.end())
            {
                c = s[i];
                index = i;
            }
        }
            
        result.push_back(c);
        hash_map.erase(c);
        start = index+1;
        minindex = findminindex(hash_map);
    }
    
    
    return result;
}

string removeDuplicateLetters2_stk(string s)
{
    unordered_map<char, int>hash_map;
        
    int count[26] = {0};
    int isvisited[26] = {0};
    
    for ( int i = 0; i < s.size(); i++)
    {
        count[s[i]-'a']++;
    }

    stack<char>stk;
    int index;
    for ( int i = 0; i < s.size(); i++)
    {
        index = s[i] - 'a';
        count[index]--;
        if (isvisited[index])
        {
            continue;
        }
        
        while(!stk.empty() && (index < stk.top()-'a') && count[stk.top()-'a'] != 0)
        {
            isvisited[stk.top()-'a'] = 0;
            stk.pop();
        }
        stk.push(s[i]);
        isvisited[index] = 1;
    }
    
    string result;
    
    while(!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }
    reverse(result.begin(), result.end());    
    return result;
}

class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        //return removeDuplicateLetters1(s);
        return removeDuplicateLetters2_stk(s);
    }
};  

//
//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n). 
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//
//
//Minimum window is "BANC". 
//
//Note:
// If there is no such window in S that covers all characters in T, return the empty string "". 
//
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 





//o(n)
string minWindow_2p(string s, string t) 
{
    int n = s.size();
    int m = t.size();
        
    unordered_map<char, int>hash_map_t;
        
    for ( int i = 0; i < t.size(); i++)
    {
        hash_map_t[t[i]]++;
    }
        
    int start = 0, end = 0, count = 0;
        
    int minlen = INT_MAX;
    string ret;
    while( end < s.size())
    {
        if (hash_map_t.find(s[end]) != hash_map_t.end())
        {
            hash_map_t[s[end]]--;
            
            if (hash_map_t[s[end]] >= 0)
            {
                count++;
            }
                
            while( count == t.size())
            {
                if ( end-start+1 < minlen)
                {
                    minlen = end-start+1;
                    ret = s.substr(start, end-start+1);
                }
                    
                if (hash_map_t.find(s[start]) != hash_map_t.end())
                {
                    hash_map_t[s[start]]++;
                    if (hash_map_t[s[start]] > 0)
                    {
                        count--;
                    }
                }
                start++;
            }
        }
        end++;
    }
    if (minlen < INT_MAX)
    {
        return ret;
    }
    
    return "";
}


//o(n^2)
string minWindow_2t(string source, string target) 
{
    string ret;
    int windows_len = INT_MAX;
    unordered_map<char, int> tofound;
    unordered_map<char, int> havefound;

   for (int i = 0; i < target.size(); i++)
   {
     tofound[target[i]]++;
   }

   int index = 0;
   int found = 0;
   int i;

   while (index < source.size())
   {
     found = 0;
     havefound.clear();

     for (i = index; i < source.size(); i++)
    {
       if (tofound[source[i]] > 0  && havefound[source[i]] < tofound[source[i]])
       {
         havefound[source[i]]++;
         found++;
       }

       if (found == target.size())
      {
        break;
      }
   }

  if (found == target.size())
  {
    if (i - index + 1 < windows_len)
    {
      ret = source.substr(index, i - index + 1);
      windows_len= i-index+1;
    }
  }

  index++;
}

return ret;
}

class Solution {
public:
    string minWindow(string s, string t) 
    {
        return minWindow_2p(s,  t);
        //return minWindow_2t(s, t); 
    }
};

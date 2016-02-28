//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters. 
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"] 
//
//You should return the indices: [0,9].
// (order does not matter). 


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string, int>dict;
        
        for ( int i = 0; i < words.size(); i++)
        {
            dict[words[i]]++;
        }
        
        int len = words[0].size(), count = 0;
        
        vector<int> result;
        for ( int i = 0; i < len; i++)
        {
            int left = i, count = 0;
            unordered_map<string, int>hash_table;
            
            // dont forget (int)s.size() as size() is unsigned int
            for ( int j = i; j <= (int)s.size()-len; j=j+len)
            {
                string substr = s.substr(j, len);
                if ( dict.find(substr) != dict.end())
                {
                    hash_table[substr]++;
                    if (hash_table[substr] <= dict[substr])
                    {
                        count++;
                    }
                    else
                    {
                        while(hash_table[substr] > dict[substr])
                        {
                            string subtemp = s.substr(left, len);
                            if (hash_table.find(subtemp) != hash_table.end())
                            {
                                hash_table[subtemp]--;
                                if (hash_table[subtemp] < dict[subtemp])
                                {
                                    count--;
                                }
                            }
                            left += len;
                        }
                    }
                    
                    if ( count == words.size())
                    {
                        result.push_back(left);
                        string subtemp = s.substr(left, len);
                        hash_table[subtemp]--;
                        count--;
                        left += len;
                    }
                }
                else
                {
                    hash_table.clear();
                    count = 0;
                    left = j+len;
                }
            }
        }
        
        return result;
    }
};

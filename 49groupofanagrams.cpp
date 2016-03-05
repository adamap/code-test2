//
//
//
//Given an array of strings, group anagrams together. 
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return: 
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//       
//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>result;
        
        if (0 == strs.size())
        {
            return result;
        }
        
        unordered_map<string, vector<int>>hash_map;
        
        for ( int i = 0; i < strs.size(); i++)
        {
            string temp(strs[i]);
            sort(temp.begin(), temp.end());
            hash_map[temp].push_back(i);
        }
        
        unordered_map<string, vector<int>>::iterator it;
        
        
        for ( it = hash_map.begin(); it != hash_map.end(); it++)
        {
            vector<string> set;
            for ( int i = 0; i < it->second.size(); i++)
            {
                set.push_back(strs[it->second[i]]);
            }
            sort(set.begin(), set.end());
            result.push_back(set);
        }
        
        return result;
    }
};

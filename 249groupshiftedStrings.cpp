//
//
//Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//"abc" -> "bcd" -> ... -> "xyz"
//
//Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
//
//For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
// Return: 
// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
//
//
// Note: For the return value, each inner list's elements must follow the lexicographic order.
//
int isShiftedString(string a, string b)
{
    if ( a.length() != b.length())
    {
        return 0;
    }
    
    int n = a.length();

    int diff = (a[0]-b[0]+26)%26;
    
    for ( int i = 1; i < n; i++)
    {
        if ( ((a[i]-b[i]+26)%26) != diff)
        {
            return 0;
        }
    }
    return 1;
}


class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) 
    {
        unordered_map<string, vector<string> > hash_map;
        
        for (int i = 0; (i < strings.size() && (strings[i].length()> 0)); i++)
        {
            int found = 0;
            for (unordered_map<string, vector<string> >::iterator it = hash_map.begin(); it != hash_map.end(); it++)
            {
                if ( isShiftedString(it->first, strings[i]) == 1)
                {
                    found  = 1;
                    it->second.push_back(strings[i]);
                }
            }
            
            if (found == 0)
            {
                hash_map[strings[i]].push_back(strings[i]);
            }
        }
        
        vector<vector<string>>result;
        
        for (unordered_map<string, vector<string> >::iterator it = hash_map.begin(); it != hash_map.end(); it++)
        {
            vector<string>set = it->second;
            sort(set.begin(), set.end());
            result.push_back(set);
        }       
        return result;        
    }

};

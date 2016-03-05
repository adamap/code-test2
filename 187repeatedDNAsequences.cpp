//
//
//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
//For example,
//Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//Return:
//["AAAAACCCCC", "CCCCCAAAAA"].
//
//
//


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> result;
        unordered_map<string, int>hash_map;
        for ( int i = 0; i <= (int)s.size()-10; i++)
        {
            string substr = s.substr(i, 10);
            if ( hash_map.find(substr) ==  hash_map.end())
            {
                hash_map[substr] = 1;
            }
            else
            {
                hash_map[substr]++;
                if ( hash_map[substr] == 2)
                {
                    result.push_back(substr);
                }
            }
        }
        
        return result;
    }
};
